#include "CPU.h"

int main() {
	CPU cpu = CPU();
	std::vector<std::string> files = { "../games/invaders.h", "../games/invaders.g", "../games/invaders.f" , "../games/invaders.e"};
	cpu.loadGame(files);
	return 0;
}