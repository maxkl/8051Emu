
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cstdint>
#include <map>
#include "HexParser.h"

namespace emu {

// http://stackoverflow.com/a/6089413/3593126
    std::istream &safeGetline(std::istream &is, std::string &t) {
        t.clear();

        // The characters in the stream are read one-by-one using a std::streambuf.
        // That is faster than reading them one-by-one using the std::istream.
        // Code that uses streambuf this way must be guarded by a sentry object.
        // The sentry object performs various tasks,
        // such as thread synchronization and updating the stream state.

        std::istream::sentry se(is, true);
        std::streambuf *sb = is.rdbuf();

        for (;;) {
            int c = sb->sbumpc();
            switch (c) {
                case '\n':
                    return is;
                case '\r':
                    if (sb->sgetc() == '\n')
                        sb->sbumpc();
                    return is;
                case EOF:
                    // Also handle the case when the last line has no line ending
                    if (t.empty()) {
                        is.setstate(std::ios::eofbit);
                        is.setstate(std::ios::failbit);
                    }
                    return is;
                default:
                    t += (char) c;
            }
        }
    }

    char parseHexDigit(char c) {
        switch (c) {
            case '0':
                return 0;
            case '1':
                return 1;
            case '2':
                return 2;
            case '3':
                return 3;
            case '4':
                return 4;
            case '5':
                return 5;
            case '6':
                return 6;
            case '7':
                return 7;
            case '8':
                return 8;
            case '9':
                return 9;
            case 'a':
            case 'A':
                return 10;
            case 'b':
            case 'B':
                return 11;
            case 'c':
            case 'C':
                return 12;
            case 'd':
            case 'D':
                return 13;
            case 'e':
            case 'E':
                return 14;
            case 'f':
            case 'F':
                return 15;
            default:
                return -1;
        }
    }

    void parseHexString(const std::string str, std::vector<std::uint8_t> &bytes) {
        size_t len = str.size();

        if (len % 2) {
            throw std::runtime_error("length is not a multiple of 2");
        }

        bytes.clear();

        for (size_t i = 0; i < len; i += 2) {
            char upper = parseHexDigit(str[i]);
            if (upper < 0) throw std::runtime_error("invalid character in hex string");
            char lower = parseHexDigit(str[i + 1]);
            if (lower < 0) throw std::runtime_error("invalid character in hex string");
            std::uint8_t byte = (static_cast<std::uint8_t>(upper) << 4) + static_cast<std::uint8_t>(lower);
            bytes.push_back(byte);
        }
    }

    bool checkChecksum(std::vector<std::uint8_t> record) {
        uint8_t sum = 0;
        for (int i = 0; i < record.size(); i++) {
            sum += record[i];
        }
        return sum == 0;
    }

    HexParser::HexParser() {

    }

    void HexParser::parse(const char *filename, std::vector<HexRecord> &records) {
        records.clear();

        std::ifstream file(filename);

        if (!file) {
            throw std::ifstream::failure("Not found");
        }

        int lineNumber = 0;
        for (std::string line; safeGetline(file, line);) {
            unsigned long lineLength = line.size();

            if (lineLength == 0) {
                throw SyntaxError(lineNumber, "empty line");
            }

            if (line[0] != ':') {
                throw SyntaxError(lineNumber, "line not starting with ':'");
            }

            if (lineLength < 3 || (lineLength % 2) != 1) {
                throw SyntaxError(lineNumber, "invalid line length");
            }

            std::vector<std::uint8_t> bytes;

            try {
                parseHexString(line.substr(1), bytes);
            } catch (const std::runtime_error err) {
                throw SyntaxError(lineNumber, err.what());
            }

//        for(int i = 0; i < bytes.size(); i++) {
//            printf("0x%02x ", bytes[i]);
//        }
//        std::cout << std::endl;

            std::uint8_t dataSize = bytes[0];
            int recordSize = 5 + dataSize;

            if (bytes.size() != recordSize) {
                throw SyntaxError(lineNumber, "unexpected record length");
            }

            std::uint16_t address = (bytes[1] << 8) + bytes[2];

            std::uint8_t rawType = bytes[3];
            if (rawType >= static_cast<uint8_t>(record_type::MAX)) {
                throw SyntaxError(lineNumber, "invalid record type");
            }
            record_type type = static_cast<record_type>(rawType);

            std::vector<std::uint8_t> data(&bytes[4], &bytes[recordSize - 1]);

            if (!checkChecksum(bytes)) {
                throw SyntaxError(lineNumber, "checksum does not match record");
            }

            HexRecord record = {
                    .type = type,
                    .address = address,
                    .dataLength = dataSize,
                    .data = data
            };
            records.push_back(record);

            lineNumber++;
        }
    }

    SyntaxError::SyntaxError(int line, const char *msg) : std::runtime_error(buildMessage(line, msg)) {}

    std::string SyntaxError::buildMessage(int line, const char *msg) {
        std::ostringstream oss;
        oss << msg << " at line " << line;
        return oss.str();
    }

}
