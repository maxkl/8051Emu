
#ifndef HEXPARSER_H
#define HEXPARSER_H

#include <iostream>
#include <cstdint>
#include <map>

namespace emu {

    class SyntaxError : public std::runtime_error {
    public:
        SyntaxError(int line, const char *msg);

    private:
        std::string buildMessage(int line, const char *msg);
    };

    enum class record_type {
        data = 0,
        end_of_file,
        extended_segment_address,
        start_segment_address,
        extended_linear_address,
        start_linear_address,

        MAX
    };
    const std::map<record_type, std::string> record_type_map = {
            {record_type::data,                     "data"},
            {record_type::end_of_file,              "end_of_file"},
            {record_type::extended_segment_address, "extended_segment_address"},
            {record_type::start_segment_address,    "start_segment_address"},
            {record_type::extended_linear_address,  "extended_linear_address"},
            {record_type::start_linear_address,     "start_linear_address"}
    };

    struct HexRecord {
        record_type type;
        uint16_t address;
        uint8_t dataLength;
        std::vector<uint8_t> data;
    };

    class HexParser {
    public:
        HexParser();

        void parse(const char *filename, std::vector<HexRecord> &records);
    };

}

#endif //HEXPARSER_H
