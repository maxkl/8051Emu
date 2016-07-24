
#include <iostream>
#include <vector>
#include "Processor.h"
#include "HexParser.h"

using namespace emu;

void printMem(const std::vector<std::uint8_t>& data, std::uint16_t start, std::uint16_t length) {
    int lineLength = 0;
    bool newLine = true;
    for(std::uint16_t i = start; i < start + length && i < data.size(); i++) {
        if(newLine) {
            printf("%04x |", i);
            newLine = false;
        }

        printf(" %02x", data[i]);

        lineLength++;
        if(lineLength >= 16) {
            printf("\n");

            lineLength = 0;
            newLine = true;
        }
    }
}

int main() {
    HexParser parser;

    std::vector<HexRecord> records;
    try {
        parser.parse("/home/max/Entwicklung/c51/test/Objects/test.hex", records);
    } catch (const SyntaxError err) {
        std::cerr << "SyntaxError: " << err.what() << std::endl;
    }
    std::cout << "Hex file parsed, got " << records.size() << " records" << std::endl;

    for(const auto& record : records) {
        printf("Type: %s, Address: 0x%04x, Data length: %i, Data:", record_type_map.at(record.type).c_str(), record.address, record.dataLength);
        for(const auto& byte : record.data) {
            printf(" %02x", byte);
        }
        std::cout << std::endl;
    }

    Processor processor;

    for(const auto& record : records) {
        switch(record.type) {
            case record_type::data:
                processor.writeRom(record.address, record.data);
                break;
            case record_type::end_of_file:
                break;
            default:
                std::cerr << "Unsupported record type " << static_cast<int>(record.type) << std::endl;
        }
    }

    printMem(processor.rom, 0, 64);

    processor.run();

    return 0;
}