#include "CPU.h"
#include <fstream>
#include <iostream>


CPU::CPU() {
	for (int i = 0; i < 65535; i++) {
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

void CPU::cycle() {
	uint8_t opcode = MEMORY[PC];

	switch (opcode) {

		//NOP Size: 1
	case 0x00: {
		PC += 1;
	}break;

		//LXI B, D16 Size: 3
	case 0x01: {

	}break;

		//STAX B Size: 1
	case 0x02: {

	}break;

		//INX B Size: 1
	case 0x03: {

	}break;

		//INR B Size: 1
	case 0x01: {

	}break;

		//DCR B Size: 1
	case 0x01: {

	}break;

		//MVI B, D8 Size: 2
	case 0x01: {

	}break;

		//RLC Size: 1
	case 0x01: {

	}break;

		//DAD B Size: 1
	case 0x01: {

	}break;

		//LDAX B Size: 1
	case 0x01: {

	}break;

		//DCX B Size: 1
	case 0x01: {

	}break;

		//INR C Size: 1
	case 0x01: {

	}break;

		//DCR C Size: 1
	case 0x01: {

	}break;

		//MVI C, D8 Size: 2
	case 0x01: {

	}break;

		//RRC Size: 1
	case 0x01: {

	}break;

		//LXI D, D16 Size: 3
	case 0x01: {

	}break;

		//STAX D Size: 1
	case 0x01: {

	}break;

		//INX D Size: 1
	case 0x01: {

	}break;

		//INR D Size: 1
	case 0x01: {

	}break;

		//DCR D Size: 1
	case 0x01: {

	}break;

		//MVI D, D8 Size: 2
	case 0x01: {

	}break;

		//RAL Size: 1
	case 0x01: {

	}break;

		//DAD D Size: 1
	case 0x01: {

	}break;

		//LDAX D Size: 1
	case 0x01: {

	}break;

		//DCX D Size: 1
	case 0x01: {

	}break;

		//INR E Size: 1
	case 0x01: {

	}break;

		//DCR E Size: 1
	case 0x01: {

	}break;

		//MVI E, D8 Size: 2
	case 0x01: {

	}break;

		//RAR Size: 1
	case 0x01: {

	}break;

		//LXI H, D16 Size: 3
	case 0x01: {

	}break;

		//SHLD adr Size: 3
	case 0x01: {

	}break;

		//INX H Size: 1
	case 0x01: {

	}break;

		//INR H Size: 1
	case 0x01: {

	}break;
	
	//DCR H Size: 1
	case 0x01: {

	}break;

	//MVI H, D8 Size: 2
	case 0x01: {

	}break;

	//DAA Size: 1
	case 0x01: {

	}break;

	//DAD H Size: 1
	case 0x01: {

	}break;

	//LHLD adr Size: 3
	case 0x01: {

	}break;

	//DCX H Size: 1
	case 0x01: {

	}break;

		//INR L Size: 1
	case 0x01: {

	}break;

		//DCR L Size: 1
	case 0x01: {

	}break;

		//MVI L, D8 Size: 2
	case 0x01: {

	}break;

		//CMA Size: 1
	case 0x01: {

	}break;

		//LXI SP, D16 Size: 3
	case 0x01: {

	}break;

		//STA adr Size: 3
	case 0x01: {

	}break;

		//INX SP Size: 1
	case 0x01: {

	}break;

		//INR M Size: 1
	case 0x01: {

	}break;

		//DCR M Size: 1
	case 0x01: {

	}break;

		//MVI M, D8 Size: 2
	case 0x01: {

	}break;

		//STC Size: 1
	case 0x01: {

	}break;

		//DAD SP Size: 1
	case 0x01: {

	}break;

		//LDA adr Size: 3
	case 0x01: {

	}break;

		//DCX SP Size: 1
	case 0x01: {

	}break;

		//MVI A, D8 Size: 2
	case 0x01: {

	}break;

		//CMC Size: 1
	case 0x01: {

	}break;

		//MOV B, B Size: 1
	case 0x01: {

	}break;

		//MOV B, C Size: 1
	case 0x01: {

	}break;

		//MOV B, D Size: 1
	case 0x01: {

	}break;

		//MOV B, E Size: 1
	case 0x01: {

	}break;

		//MOV B, H Size: 1
	case 0x01: {

	}break;

		//MOV B, L Size: 1
	case 0x01: {

	}break;

		//MOV B, M Size: 1
	case 0x01: {

	}break;

		//MOV B, A Size: 1
	case 0x01: {

	}break;

		//MOV C, B Size: 1
	case 0x01: {

	}break;

		//MOV C, C Size: 1
	case 0x01: {

	}break;

		//MOV C, D Size: 1
	case 0x01: {

	}break;

		//MOV C, E Size: 1
	case 0x01: {

	}break;

		//MOV C, H Size: 1
	case 0x01: {

	}break;

		//MOV C, L Size: 1
	case 0x01: {

	}break;

		//MOV C, M Size: 1
	case 0x01: {

	}break;

		//MOV C, A Size: 1
	case 0x01: {

	}break;

		//MOV D, B Size: 1
	case 0x01: {

	}break;

		//MOV D, C Size: 1
	case 0x01: {

	}break;

		//MOV D, D Size: 1
	case 0x01: {

	}break;

		//MOV D, E Size: 1
	case 0x01: {

	}break;

		//MOV D, H Size: 1
	case 0x01: {

	}break;

		//MOV D, L Size: 1
	case 0x01: {

	}break;

		//MOV D, M Size: 1
	case 0x01: {

	}break;

		//MOV D, A Size: 1
	case 0x01: {

	}break;

		//MOV E, B Size: 1
	case 0x01: {

	}break;

		//MOV E, C Size: 1
	case 0x01: {

	}break;

		//MOV E, D Size: 1
	case 0x01: {

	}break;

		//MOV E, E Size: 1
	case 0x01: {

	}break;

		//MOV E, H Size: 1
	case 0x01: {

	}break;

		//MOV E, L Size: 1
	case 0x01: {

	}break;

		//MOV E, M Size: 1
	case 0x01: {

	}break;

		//MOV E, A Size: 1
	case 0x01: {

	}break;

		//MOV H, B Size: 1
	case 0x01: {

	}break;

		//MOV H, C Size: 1
	case 0x01: {

	}break;

		//MOV H, D Size: 1
	case 0x01: {

	}break;

		//MOV H, E Size: 1
	case 0x01: {

	}break;

		//MOV H, H Size: 1
	case 0x01: {

	}break;

		//MOV H, L Size: 1
	case 0x01: {

	}break;

		//MOV H, M Size: 1
	case 0x01: {

	}break;

		//MOV H, A Size: 1
	case 0x01: {

	}break;

		//MOV L, B Size: 1
	case 0x01: {

	}break;

		//MOV L, C Size: 1
	case 0x01: {

	}break;

		//MOV L, D Size: 1
	case 0x01: {

	}break;

		//MOV L, E Size: 1
	case 0x01: {

	}break;

		//MOV L, H Size: 1
	case 0x01: {

	}break;

		//MOV L, L Size: 1
	case 0x01: {

	}break;

		//MOV L, M Size: 1
	case 0x01: {

	}break;

		//MOV L, A Size: 1
	case 0x01: {

	}break;

		//MOV M, B Size: 1
	case 0x01: {

	}break;

		//MOV M, C Size: 1
	case 0x01: {

	}break;

		//MOV M, D Size: 1
	case 0x01: {

	}break;

		//MOV M, E Size: 1
	case 0x01: {

	}break;

		//MOV M, H Size: 1
	case 0x01: {

	}break;

		//MOV M, L Size: 1
	case 0x01: {

	}break;

		//HLT Size: 1
	case 0x01: {

	}break;

		//MOV M, A Size: 1
	case 0x01: {

	}break;

		//MOV A, B Size: 1
	case 0x01: {

	}break;

		//MOV A, C Size: 1
	case 0x01: {

	}break;

		//MOV A, D Size: 1
	case 0x01: {

	}break;

		//MOV A, E Size: 1
	case 0x01: {

	}break;

		//MOV A, H Size: 1
	case 0x01: {

	}break;

		//MOV A, L Size: 1
	case 0x01: {

	}break;

		//MOV A, M Size: 1
	case 0x01: {

	}break;

		//MOV A, A Size: 1
	case 0x01: {

	}break;

		//ADD B Size: 1
	case 0x01: {

	}break;

		//ADD C Size: 1
	case 0x01: {

	}break;

		//ADD D Size: 1
	case 0x01: {

	}break;

		//ADD E Size: 1
	case 0x01: {

	}break;

		//ADD H Size: 1
	case 0x01: {

	}break;

		//ADD L Size: 1
	case 0x01: {

	}break;

		//ADD M Size: 1
	case 0x01: {

	}break;

		//ADD A Size: 1
	case 0x01: {

	}break;

		//ADC B Size: 1
	case 0x01: {

	}break;

		//ADC C Size: 1
	case 0x01: {

	}break;

		//ADC D Size: 1
	case 0x01: {

	}break;

		//ADC E Size: 1
	case 0x01: {

	}break;

		//ADC H Size: 1
	case 0x01: {

	}break;

		//ADC L Size: 1
	case 0x01: {

	}break;

		//ADC M Size: 1
	case 0x01: {

	}break;

		//ADC A Size: 1
	case 0x01: {

	}break;

		//SUB B Size: 1
	case 0x01: {

	}break;

		//SUB C Size: 1
	case 0x01: {

	}break;

		//SUB D Size: 1
	case 0x01: {

	}break;

		//SUB E Size: 1
	case 0x01: {

	}break;

		//SUB H Size: 1
	case 0x01: {

	}break;

		//SUB L Size: 1
	case 0x01: {

	}break;

		//SUB M Size: 1
	case 0x01: {

	}break;

		//SUB A Size: 1
	case 0x01: {

	}break;

		//SBB B Size: 1
	case 0x01: {

	}break;

		//SBB C Size: 1
	case 0x01: {

	}break;

		//SBB D Size: 1
	case 0x01: {

	}break;
		
		//SBB E Size: 1
	case 0x01: {

	}break;

		//SBB H Size: 1
	case 0x01: {

	}break;

		//SBB L Size: 1
	case 0x01: {

	}break;

		//SBB M Size: 1
	case 0x01: {

	}break;

		//SBB A Size: 1
	case 0x01: {

	}break;

		//ANA B Size: 1
	case 0x01: {

	}break;

		//ANA C Size: 1
	case 0x01: {

	}break;

		//ANA D Size: 1
	case 0x01: {

	}break;

		//ANA E Size: 1
	case 0x01: {

	}break;

		//ANA H Size: 1
	case 0x01: {

	}break;

		//ANA L Size: 1
	case 0x01: {

	}break;

		//ANA M Size: 1
	case 0x01: {

	}break;

		//ANA A Size: 1
	case 0x01: {

	}break;

		//XRA B Size: 1
	case 0x01: {

	}break;

		//XRA C Size: 1
	case 0x01: {

	}break;

		//XRA D Size: 1
	case 0x01: {

	}break;

		//XRA E Size: 1
	case 0x01: {

	}break;

		//XRA H Size: 1
	case 0x01: {

	}break;

		//XRA L Size: 1
	case 0x01: {

	}break;

		//XRA M Size: 1
	case 0x01: {

	}break;

		//XRA A Size: 1
	case 0x01: {

	}break;

		//ORA B Size: 1
	case 0x01: {

	}break;

		//ORA C Size: 1
	case 0x01: {

	}break;

		//ORA D Size: 1
	case 0x01: {

	}break;

		//ORA E Size: 1
	case 0x01: {

	}break;

		//ORA H Size: 1
	case 0x01: {

	}break;

		//ORA L Size: 1
	case 0x01: {

	}break;

		//ORA M Size: 1
	case 0x01: {

	}break;

		//ORA A Size: 1
	case 0x01: {

	}break;

		//CMP B Size: 1
	case 0x01: {

	}break;

		//CMP C Size: 1
	case 0x01: {

	}break;

		//CMP D Size: 1
	case 0x01: {

	}break;

		//CMP E Size: 1
	case 0x01: {

	}break;

		//CMP H Size: 1
	case 0x01: {

	}break;

		//CMP L Size: 1
	case 0x01: {

	}break;

		//CMP M Size: 1
	case 0x01: {

	}break;

		//CMP A Size: 1
	case 0x01: {

	}break;

		//RNZ Size: 1
	case 0x01: {

	}break;

		//POP B Size: 1
	case 0x01: {

	}break;

		//JNZ adr Size: 3
	case 0x01: {

	}break;

		//JMP adr Size: 3
	case 0x01: {

	}break;

		//CNZ adr Size: 3
	case 0x01: {

	}break;

		//PUSH B Size: 1
	case 0x01: {

	}break;

		//ADI D8 Size: 1
	case 0x01: {

	}break;

		//RST 0 Size: 1
	case 0x01: {

	}break;

		//RZ Size: 1
	case 0x01: {

	}break;

		//RET Size: 1
	case 0x01: {

	}break;

		//JZ adr Size: 1
	case 0x01: {

	}break;

		//CZ adr Size: 3
	case 0x01: {

	}break;

		//CALL adr Size: 3
	case 0x01: {

	}break;

		//ACI D8 Size: 2
	case 0x01: {

	}break;

		//RST 1 Size: 1
	case 0x01: {

	}break;

		//RNC Size: 1
	case 0x01: {

	}break;

		//POP D Size: 1
	case 0x01: {

	}break;

		//JNC adr Size: 3
	case 0x01: {

	}break;

		//OUT D8 Size: 1
	case 0x01: {

	}break;

		//CNC adr Size: 1
	case 0x01: {

	}break;

		//PUSH D Size: 1
	case 0x01: {

	}break;

		//SUI D8 Size: 2
	case 0x01: {

	}break;

		//RST 2 Size: 1
	case 0x01: {

	}break;

		//RC Size: 1
	case 0x01: {

	}break;

		//JC adr Size: 3
	case 0x01: {

	}break;

		//IN D8 Size: 2
	case 0x01: {

	}break;

		//CC adr Size: 3
	case 0x01: {

	}break;

		//SBI D8 Size: 2
	case 0x01: {

	}break;

		//RST 3 Size: 1
	case 0x01: {

	}break;

		//RPO Size: 1
	case 0x01: {

	}break;

		//POP H Size: 1
	case 0x01: {

	}break;

		//JPO adr Size: 3
	case 0x01: {

	}break;

		//XTHL Size: 1
	case 0x01: {

	}break;

		//CPO adr Size: 3
	case 0x01: {

	}break;

		//PUSH H Size: 1
	case 0x01: {

	}break;

		//ANI D8 Size: 2
	case 0x01: {

	}break;

		//RST 4 Size: 1
	case 0x01: {

	}break;

		//RPE Size: 1
	case 0x01: {

	}break;

		//PCHL Size: 1
	case 0x01: {

	}break;

		//JPE adr Size: 3
	case 0x01: {

	}break;

		//XCHG Size: 1
	case 0x01: {

	}break;

		//CPE adr Size: 3
	case 0x01: {

	}break;

		//XRI D8 Size: 2
	case 0x01: {

	}break;

		//RST 5 Size: 1
	case 0x01: {

	}break;

		//RP Size: 1
	case 0x01: {

	}break;

		//POP PSW Size: 1
	case 0x01: {

	}break;

		//JP adr Size: 3
	case 0x01: {

	}break;

		//DI Size: 1
	case 0x01: {

	}break;

		//CP adr Size: 3
	case 0x01: {

	}break;

		//PUSH PSW Size: 1
	case 0x01: {

	}break;

		//ORI D8 Size: 2
	case 0x01: {

	}break;

		//RST 6 Size: 1
	case 0x01: {

	}break;

		//RM Size: 1
	case 0x01: {

	}break;

		//SPHL Size: 1
	case 0x01: {

	}break;

		//JM adr Size: 3
	case 0x01: {

	}break;

		//EI Size: 1
	case 0x01: {

	}break;

		//CM adr Size: 3
	case 0x01: {

	}break;

		//CPI D8 Size: 2
	case 0x01: {

	}break;

		//RST 7 Size: 1
	case 0x01: {

	}break;









































}