#include "CPU.h"
#include <iostream>

int main() {
	CPU cpu = CPU();
	std::vector<std::string> files = { "../games/invaders.h", "../games/invaders.g", "../games/invaders.f" , "../games/invaders.e"};
	cpu.loadGame(files);

	bool quit = false;
	char state = 'n';
	while (!quit) {
		std::cout << "PC: " << std::hex << cpu.PC << " ";
		cpu.cycle();
	}
	

		
	

	return 0;
}