#include "CPU.h"
#include <fstream>
#include <iostream>


CPU::CPU() {
	for (int i = 0; i < 65536; i++) {
		MEMORY[i] = 0;
	}
	
	for (int r = 0; r < 7; r++) {
		REGISTERS[r] = 0;
	}

	PC = 0; 

	SP = 0;
}

void CPU::loadGame(std::vector<std::string> files) {
	
	int start_adress = 0;
	for (int fn = 0; fn < files.size(); fn++) {
		std::ifstream file(files[fn], std::ios::binary | std::ios::ate);

		if (file.is_open()) {
			std::streampos size = file.tellg();

			file.seekg(0, std::ios::beg);
			file.read((char*)&MEMORY[start_adress], size);
			file.close();
			
		}
		else {
			exit(1);
		}
		start_adress += 0x800;
	}
	
}