#include "CPU.h"
#include <iostream>

int main() {
	CPU cpu = CPU();
	std::vector<std::string> files = { "../games/invaders.h", "../games/invaders.g", "../games/invaders.f" , "../games/invaders.e"};
	cpu.loadGame(files);

	bool quit = false;
	int cycles = 0;
	bool debugPrintOn = false;
	while (!quit) {
		if (debugPrintOn) std::cout << "PC: " << std::hex << cpu.PC << " " << std::endl;
		cpu.cycle(cycles);
		cycles++;
	}
	return 0;
}