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
	case 0x04: {

	}break;

		//DCR B Size: 1
	case 0x05: {

	}break;

		//MVI B, D8 Size: 2
	case 0x06: {

	}break;

		//RLC Size: 1
	case 0x07: {

	}break;

		//DAD B Size: 1
	case 0x09: {

	}break;

		//LDAX B Size: 1
	case 0x0a: {

	}break;

		//DCX B Size: 1
	case 0x0b: {

	}break;

		//INR C Size: 1
	case 0x0c: {

	}break;

		//DCR C Size: 1
	case 0x0d: {

	}break;

		//MVI C, D8 Size: 2
	case 0x0e: {

	}break;

		//RRC Size: 1
	case 0x0f: {

	}break;

		//LXI D, D16 Size: 3
	case 0x11: {

	}break;

		//STAX D Size: 1
	case 0x12: {

	}break;

		//INX D Size: 1
	case 0x13: {

	}break;

		//INR D Size: 1
	case 0x14: {

	}break;

		//DCR D Size: 1
	case 0x15: {

	}break;

		//MVI D, D8 Size: 2
	case 0x16: {

	}break;

		//RAL Size: 1
	case 0x17: {

	}break;

		//DAD D Size: 1
	case 0x19: {

	}break;

		//LDAX D Size: 1
	case 0x1a: {

	}break;

		//DCX D Size: 1
	case 0x1b: {

	}break;

		//INR E Size: 1
	case 0x1c: {

	}break;

		//DCR E Size: 1
	case 0x1d: {

	}break;

		//MVI E, D8 Size: 2
	case 0x1e: {

	}break;

		//RAR Size: 1
	case 0x1f: {

	}break;

		//LXI H, D16 Size: 3
	case 0x21: {

	}break;

		//SHLD adr Size: 3
	case 0x22: {

	}break;

		//INX H Size: 1
	case 0x23: {

	}break;

		//INR H Size: 1
	case 0x24: {

	}break;
	
	//DCR H Size: 1
	case 0x25: {

	}break;

	//MVI H, D8 Size: 2
	case 0x26: {

	}break;

	//DAA Size: 1
	case 0x27: {

	}break;

	//DAD H Size: 1
	case 0x29: {

	}break;

	//LHLD adr Size: 3
	case 0x2a: {

	}break;

	//DCX H Size: 1
	case 0x2b: {

	}break;

		//INR L Size: 1
	case 0x2c: {

	}break;

		//DCR L Size: 1
	case 0x2d: {

	}break;

		//MVI L, D8 Size: 2
	case 0x2e: {

	}break;

		//CMA Size: 1
	case 0x2f: {

	}break;

		//LXI SP, D16 Size: 3
	case 0x31: {

	}break;

		//STA adr Size: 3
	case 0x32: {

	}break;

		//INX SP Size: 1
	case 0x33: {

	}break;

		//INR M Size: 1
	case 0x34: {

	}break;

		//DCR M Size: 1
	case 0x35: {

	}break;

		//MVI M, D8 Size: 2
	case 0x36: {

	}break;

		//STC Size: 1
	case 0x37: {

	}break;

		//DAD SP Size: 1
	case 0x39: {

	}break;

		//LDA adr Size: 3
	case 0x3a: {

	}break;

		//DCX SP Size: 1
	case 0x3b: {

	}break;

		//INR A Size: 1
	case 0x3c: {

	}break;

		//DCR A Size: 1
	case 0x3d: {

	}break;

		//MVI A, D8 Size: 2
	case 0x3e: {

	}break;

		//CMC Size: 1
	case 0x3f: {

	}break;

		//MOV B, B Size: 1
	case 0x40: {

	}break;

		//MOV B, C Size: 1
	case 0x41: {

	}break;

		//MOV B, D Size: 1
	case 0x42: {

	}break;

		//MOV B, E Size: 1
	case 0x43: {

	}break;

		//MOV B, H Size: 1
	case 0x44: {

	}break;

		//MOV B, L Size: 1
	case 0x45: {

	}break;

		//MOV B, M Size: 1
	case 0x46: {

	}break;

		//MOV B, A Size: 1
	case 0x47: {

	}break;

		//MOV C, B Size: 1
	case 0x48: {

	}break;

		//MOV C, C Size: 1
	case 0x49: {

	}break;

		//MOV C, D Size: 1
	case 0x4a: {

	}break;

		//MOV C, E Size: 1
	case 0x4b: {

	}break;

		//MOV C, H Size: 1
	case 0x4c: {

	}break;

		//MOV C, L Size: 1
	case 0x4d: {

	}break;

		//MOV C, M Size: 1
	case 0x4e: {

	}break;

		//MOV C, A Size: 1
	case 0x4f: {

	}break;

		//MOV D, B Size: 1
	case 0x50: {

	}break;

		//MOV D, C Size: 1
	case 0x51: {

	}break;

		//MOV D, D Size: 1
	case 0x52: {

	}break;

		//MOV D, E Size: 1
	case 0x53: {

	}break;

		//MOV D, H Size: 1
	case 0x54: {

	}break;

		//MOV D, L Size: 1
	case 0x55: {

	}break;

		//MOV D, M Size: 1
	case 0x56: {

	}break;

		//MOV D, A Size: 1
	case 0x57: {

	}break;

		//MOV E, B Size: 1
	case 0x58: {

	}break;

		//MOV E, C Size: 1
	case 0x59: {

	}break;

		//MOV E, D Size: 1
	case 0x5a: {

	}break;

		//MOV E, E Size: 1
	case 0x5b: {

	}break;

		//MOV E, H Size: 1
	case 0x5c: {

	}break;

		//MOV E, L Size: 1
	case 0x5d: {

	}break;

		//MOV E, M Size: 1
	case 0x5e: {

	}break;

		//MOV E, A Size: 1
	case 0x5f: {

	}break;

		//MOV H, B Size: 1
	case 0x60: {

	}break;

		//MOV H, C Size: 1
	case 0x61: {

	}break;

		//MOV H, D Size: 1
	case 0x62: {

	}break;

		//MOV H, E Size: 1
	case 0x63: {

	}break;

		//MOV H, H Size: 1
	case 0x64: {

	}break;

		//MOV H, L Size: 1
	case 0x65: {

	}break;

		//MOV H, M Size: 1
	case 0x66: {

	}break;

		//MOV H, A Size: 1
	case 0x67: {

	}break;

		//MOV L, B Size: 1
	case 0x68: {

	}break;

		//MOV L, C Size: 1
	case 0x69: {

	}break;

		//MOV L, D Size: 1
	case 0x6a: {

	}break;

		//MOV L, E Size: 1
	case 0x6b: {

	}break;

		//MOV L, H Size: 1
	case 0x6c: {

	}break;

		//MOV L, L Size: 1
	case 0x6d: {

	}break;

		//MOV L, M Size: 1
	case 0x6e: {

	}break;

		//MOV L, A Size: 1
	case 0x6f: {

	}break;

		//MOV M, B Size: 1
	case 0x70: {

	}break;

		//MOV M, C Size: 1
	case 0x71: {

	}break;

		//MOV M, D Size: 1
	case 0x72: {

	}break;

		//MOV M, E Size: 1
	case 0x73: {

	}break;

		//MOV M, H Size: 1
	case 0x074: {

	}break;

		//MOV M, L Size: 1
	case 0x75: {

	}break;

		//HLT Size: 1
	case 0x76: {

	}break;

		//MOV M, A Size: 1
	case 0x77: {

	}break;

		//MOV A, B Size: 1
	case 0x78: {

	}break;

		//MOV A, C Size: 1
	case 0x79: {

	}break;

		//MOV A, D Size: 1
	case 0x7a: {

	}break;

		//MOV A, E Size: 1
	case 0x7b: {

	}break;

		//MOV A, H Size: 1
	case 0x7c: {

	}break;

		//MOV A, L Size: 1
	case 0x7d: {

	}break;

		//MOV A, M Size: 1
	case 0x7e: {

	}break;

		//MOV A, A Size: 1
	case 0x7f: {

	}break;

		//ADD B Size: 1
	case 0x80: {

	}break;

		//ADD C Size: 1
	case 0x81: {

	}break;

		//ADD D Size: 1
	case 0x82: {

	}break;

		//ADD E Size: 1
	case 0x83: {

	}break;

		//ADD H Size: 1
	case 0x84: {

	}break;

		//ADD L Size: 1
	case 0x85: {

	}break;

		//ADD M Size: 1
	case 0x86: {

	}break;

		//ADD A Size: 1
	case 0x87: {

	}break;

		//ADC B Size: 1
	case 0x88: {

	}break;

		//ADC C Size: 1
	case 0x89: {

	}break;

		//ADC D Size: 1
	case 0x8a: {

	}break;

		//ADC E Size: 1
	case 0x8b: {

	}break;

		//ADC H Size: 1
	case 0x8c: {

	}break;

		//ADC L Size: 1
	case 0x8d: {

	}break;

		//ADC M Size: 1
	case 0x8e: {

	}break;

		//ADC A Size: 1
	case 0x8f: {

	}break;

		//SUB B Size: 1
	case 0x90: {

	}break;

		//SUB C Size: 1
	case 0x91: {

	}break;

		//SUB D Size: 1
	case 0x92: {

	}break;

		//SUB E Size: 1
	case 0x93: {

	}break;

		//SUB H Size: 1
	case 0x94: {

	}break;

		//SUB L Size: 1
	case 0x95: {

	}break;

		//SUB M Size: 1
	case 0x96: {

	}break;

		//SUB A Size: 1
	case 0x97: {

	}break;

		//SBB B Size: 1
	case 0x98: {

	}break;

		//SBB C Size: 1
	case 0x99: {

	}break;

		//SBB D Size: 1
	case 0x9a: {

	}break;
		
		//SBB E Size: 1
	case 0x9b: {

	}break;

		//SBB H Size: 1
	case 0x9c: {

	}break;

		//SBB L Size: 1
	case 0x9d: {

	}break;

		//SBB M Size: 1
	case 0x9e: {

	}break;

		//SBB A Size: 1
	case 0x9f: {

	}break;

		//ANA B Size: 1
	case 0xa0: {

	}break;

		//ANA C Size: 1
	case 0xa1: {

	}break;

		//ANA D Size: 1
	case 0xa2: {

	}break;

		//ANA E Size: 1
	case 0xa3: {

	}break;

		//ANA H Size: 1
	case 0xa4: {

	}break;

		//ANA L Size: 1
	case 0xa5: {

	}break;

		//ANA M Size: 1
	case 0xa6: {

	}break;

		//ANA A Size: 1
	case 0xa7: {

	}break;

		//XRA B Size: 1
	case 0xa8: {

	}break;

		//XRA C Size: 1
	case 0xa9: {

	}break;

		//XRA D Size: 1
	case 0xaa: {

	}break;

		//XRA E Size: 1
	case 0xab: {

	}break;

		//XRA H Size: 1
	case 0xac: {

	}break;

		//XRA L Size: 1
	case 0xad: {

	}break;

		//XRA M Size: 1
	case 0xae: {

	}break;

		//XRA A Size: 1
	case 0xaf: {

	}break;

		//ORA B Size: 1
	case 0xb0: {

	}break;

		//ORA C Size: 1
	case 0xb1: {

	}break;

		//ORA D Size: 1
	case 0xb2: {

	}break;

		//ORA E Size: 1
	case 0xb3: {

	}break;

		//ORA H Size: 1
	case 0xb4: {

	}break;

		//ORA L Size: 1
	case 0xb5: {

	}break;

		//ORA M Size: 1
	case 0xb6: {

	}break;

		//ORA A Size: 1
	case 0xb7: {

	}break;

		//CMP B Size: 1
	case 0xb8: {

	}break;

		//CMP C Size: 1
	case 0xb9: {

	}break;

		//CMP D Size: 1
	case 0xba: {

	}break;

		//CMP E Size: 1
	case 0xbb: {

	}break;

		//CMP H Size: 1
	case 0xbc: {

	}break;

		//CMP L Size: 1
	case 0xbd: {

	}break;

		//CMP M Size: 1
	case 0xbe: {

	}break;

		//CMP A Size: 1
	case 0xbf: {

	}break;

		//RNZ Size: 1
	case 0xc0: {

	}break;

		//POP B Size: 1
	case 0xc1: {

	}break;

		//JNZ adr Size: 3
	case 0xc2: {

	}break;

		//JMP adr Size: 3
	case 0xc3: {

	}break;

		//CNZ adr Size: 3
	case 0xc4: {

	}break;

		//PUSH B Size: 1
	case 0xc5: {

	}break;

		//ADI D8 Size: 1
	case 0xc6: {

	}break;

		//RST 0 Size: 1
	case 0xc7: {

	}break;

		//RZ Size: 1
	case 0xc8: {

	}break;

		//RET Size: 1
	case 0xc9: {

	}break;

		//JZ adr Size: 1
	case 0xca: {

	}break;

		//CZ adr Size: 3
	case 0xcc: {

	}break;

		//CALL adr Size: 3
	case 0xcd: {

	}break;

		//ACI D8 Size: 2
	case 0xce: {

	}break;

		//RST 1 Size: 1
	case 0xcf: {

	}break;

		//RNC Size: 1
	case 0xd0: {

	}break;

		//POP D Size: 1
	case 0xd1: {

	}break;

		//JNC adr Size: 3
	case 0xd2: {

	}break;

		//OUT D8 Size: 1
	case 0xd3: {

	}break;

		//CNC adr Size: 1
	case 0xd4: {

	}break;

		//PUSH D Size: 1
	case 0xd5: {

	}break;

		//SUI D8 Size: 2
	case 0xd6: {

	}break;

		//RST 2 Size: 1
	case 0xd7: {

	}break;

		//RC Size: 1
	case 0xd8: {

	}break;

		//JC adr Size: 3
	case 0xda: {

	}break;

		//IN D8 Size: 2
	case 0xdb: {

	}break;

		//CC adr Size: 3
	case 0xdc: {

	}break;

		//SBI D8 Size: 2
	case 0xde: {

	}break;

		//RST 3 Size: 1
	case 0xdf: {

	}break;

		//RPO Size: 1
	case 0xe0: {

	}break;

		//POP H Size: 1
	case 0xe1: {

	}break;

		//JPO adr Size: 3
	case 0xe2: {

	}break;

		//XTHL Size: 1
	case 0xe3: {

	}break;

		//CPO adr Size: 3
	case 0xe4: {

	}break;

		//PUSH H Size: 1
	case 0xe5: {

	}break;

		//ANI D8 Size: 2
	case 0xe6: {

	}break;

		//RST 4 Size: 1
	case 0xe7: {

	}break;

		//RPE Size: 1
	case 0xe8: {

	}break;

		//PCHL Size: 1
	case 0xe9: {

	}break;

		//JPE adr Size: 3
	case 0xea: {

	}break;

		//XCHG Size: 1
	case 0xeb: {

	}break;

		//CPE adr Size: 3
	case 0xec: {

	}break;

		//XRI D8 Size: 2
	case 0xee: {

	}break;

		//RST 5 Size: 1
	case 0xef: {

	}break;

		//RP Size: 1
	case 0xf0: {

	}break;

		//POP PSW Size: 1
	case 0xf1: {

	}break;

		//JP adr Size: 3
	case 0xf2: {

	}break;

		//DI Size: 1
	case 0xf3: {

	}break;

		//CP adr Size: 3
	case 0xf4: {

	}break;

		//PUSH PSW Size: 1
	case 0xf5: {

	}break;

		//ORI D8 Size: 2
	case 0xf6: {

	}break;

		//RST 6 Size: 1
	case 0xf7: {

	}break;

		//RM Size: 1
	case 0xf8: {

	}break;

		//SPHL Size: 1
	case 0xf9: {

	}break;

		//JM adr Size: 3
	case 0xfa: {

	}break;

		//EI Size: 1
	case 0xfb: {

	}break;

		//CM adr Size: 3
	case 0xfc: {

	}break;

		//CPI D8 Size: 2
	case 0xfe: {

	}break;

		//RST 7 Size: 1
	case 0xff: {

	}break;









































}