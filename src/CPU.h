#pragma once
#include <cstdint>
#include <vector>
#include <string>

class CPU{
public:
    CPU();
    void loadGame(std::vector<std::string> files);
    void cycle(int& currentCycle);
    void debugCycles(std::string instructionName, int opcode);
    uint8_t MEMORY[4096*16]; //65k bytes of memory
    uint8_t REGISTERS[7]; // 7 8-bit registers

    uint16_t PC;
    uint16_t* SP;

    unsigned char cf; //Carry flag
    unsigned char cfa;//Auxiliary carry flag
    unsigned char sf; //Sign flag
    unsigned char zf; //Zero flag
    unsigned char pf; //Parity flag;
};