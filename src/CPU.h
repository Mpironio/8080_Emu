#pragma once
#include <cstdint>
#include <vector>
#include <string>

class CPU{
public:
    CPU();
    void loadGame(std::vector<std::string> files);
    void cycle();
    uint8_t MEMORY[65535]; //65k bytes of memory
    uint8_t REGISTERS[7]; // 7 8-bit registers

    uint16_t PC;

    uint16_t SP;
};