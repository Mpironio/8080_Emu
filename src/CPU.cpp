#include "CPU.h"
#include <fstream>
#include <iostream>


CPU::CPU() {
	for (int i = 0; i < (4096*16); i++) {
		MEMORY[i] = 0;
	}
	
	for (int r = 0; r < 7; r++) {
		REGISTERS[r] = 0;
	}

	PC = 0; 
	SP = 0;

	unsigned char cf = 0; //Carry flag
	unsigned char cfa= 0;//Auxiliary carry flag
	unsigned char sf = 0; //Sign flag
	unsigned char zf = 0; //Zero flag
	unsigned char pf = 0; //Parity flag;
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

void CPU::debugCycles(std::string instructionName, int opcode) {
	std::cout << "Opcode: " << std::hex << opcode << " Instruction: " << instructionName << "\n";
	std::cout << "-----------------------------------------------------" << "\n";
}


//DATA
/*
	REGISTERS: A B C D E H L
			   0 1 2 3 4 5 6
*/


//HAY QUE ARREGLAR LO DEL SP
void CPU::cycle(int& currentCyc) {
	uint8_t opcode = MEMORY[PC];
	bool debugPrintOn;
	debugPrintOn = currentCyc > 37388? true : false; //1544 es cuando termina de copiar la memoria
	//debugPrintOn = true;
	if(debugPrintOn) std::cout << std::hex << "Opcode: " << (int)opcode << " Instruction: ";
	switch (opcode) {

		//NOP Size: 1
	case 0x00: {
		if(debugPrintOn) std::cout << "0x00 NOP" << "\n";
		PC += 1;
	}break;
		//LXI B, D16 Size: 3
	case 0x01: {
		if (debugPrintOn) std::cout << "LXI B, D16: " << std::hex << "B <- " << MEMORY[PC + 2] << MEMORY[PC + 1] << "\n";
		REGISTERS[1] = MEMORY[PC + 2];
		REGISTERS[2] = MEMORY[PC + 1];
		PC += 3;
	}break;

		//STAX B Size: 1
	case 0x02: {

	}break;

		//INX B Size: 1
	case 0x03: {
		//
	}break;

		//INR B Size: 1
	case 0x04: {
		
		
		
		
		
	}break;

		//DCR B Size: 1
	case 0x05: {
		if (debugPrintOn) std::cout << "DCR B " << std::hex << (int)REGISTERS[1] << " <- ";
		REGISTERS[1] -= 1;
		//Flags handling
		REGISTERS[1] & (0x1 << 7) ? sf = 1 : sf = 0;	//sign flag
		REGISTERS[1] == 0 ? zf = 1 : zf = 0;			//zero flag
		REGISTERS[1] % 2 == 0 ? pf = 1 : pf = 0;		//parity flag
		REGISTERS[1] & 0x0 ? cfa = 1 : cfa = 0;			//auxiliary carry flag


		if (debugPrintOn) std::cout << std::hex << (int)REGISTERS[1] << "\n";
		PC += 1;
	}break;

		//MVI B, D8 Size: 2
	case 0x06: {
		if (debugPrintOn) std::cout << "MVI B, D8  B<- " << std::hex << (int)MEMORY[PC + 1]  << "\n";
		REGISTERS[1] = MEMORY[PC + 1];
		PC += 2;
	}break;

		//RLC Size: 1
	case 0x07: {

	}break;

		//DAD B Size: 1
	case 0x09: {
		if(debugPrintOn) std::cout << "DAD B " << std::hex << "HL += BC " << "\n";
		uint16_t BC = REGISTERS[2] << 8 | REGISTERS[1];
		uint16_t HL = REGISTERS[5] << 8 | REGISTERS[4];
		uint16_t result = HL + BC;
		REGISTERS[5] = (result & 0xFF00) >> 8;
		REGISTERS[6] = result & 0xFF;
		PC += 1;
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
		if (debugPrintOn) std::cout << "DCR C " << std::hex << (int)REGISTERS[2] << " <- " << (int)REGISTERS[2]-- << "\n";
		REGISTERS[2] -= 1;
		//Flags handling
		REGISTERS[2] & (0x1 << 7) ? sf = 1 : sf = 0;	//sign flag
		REGISTERS[2] == 0 ? zf = 1 : zf = 0;			//zero flag
		REGISTERS[2] % 2 == 0 ? pf = 1 : pf = 0;		//parity flag
		REGISTERS[2] & 0x0 ? cfa = 1 : cfa = 0;			//auxiliary carry flag


		if (debugPrintOn) std::cout << std::hex << (int)REGISTERS[2];
		PC += 1;
	}break;

		//MVI C, D8 Size: 2
	case 0x0e: {
		if (debugPrintOn) std::cout << "MVI C, D8  C<- " << std::hex << (int)MEMORY[PC + 1] << "\n";
		REGISTERS[2] = MEMORY[PC + 1];
		PC += 2;
	}break;

		//RRC Size: 1
	case 0x0f: {

	}break;

		//LXI D, D16 Size: 3
	case 0x11: {
		uint8_t fstB = MEMORY[PC + 2];
		uint8_t sndB = MEMORY[PC + 1];
		if (debugPrintOn) std::cout << "LXI D, D16  " << std::hex << "D<- " << (int)fstB << " E<- " << (int)sndB << "\n";
		REGISTERS[3] = fstB;
		REGISTERS[4] = sndB;
		PC += 3;

	}break;

		//STAX D Size: 1
	case 0x12: {

	}break;

		//INX D Size: 1
	case 0x13: {
		if (debugPrintOn) std::cout << "INX D " << std::hex << (int)REGISTERS[3] << (int)REGISTERS[4] << " <- ";
		REGISTERS[4] == 0xff ? REGISTERS[4] = 0x00, REGISTERS[3] += 1 : REGISTERS[4] += 0x01;
		if (debugPrintOn) std::cout << std::hex << (int)REGISTERS[3] << (int)REGISTERS[4] << "\n";
		PC += 1;
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
		uint16_t HL = REGISTERS[6] << 8 | REGISTERS[5];
		uint16_t DE = REGISTERS[4] << 8 | REGISTERS[3];
		cf = (HL >> 15) & (DE >> 15); //me fijo si tiene carry
		if (debugPrintOn) std::cout << "ADD HL + HL <- " << std::hex << (HL + DE) << " CF: " << cf << "\n";
		PC += 1;
	}break;

		//LDAX D Size: 1
	case 0x1a: {
		REGISTERS[0] = MEMORY[(REGISTERS[3] << 8) + REGISTERS[4]];
		if (debugPrintOn) std::cout << "LDAX D  " << "A <- " << std::hex << "[" << (int)REGISTERS[0] << "] rDE" << "\n";
		PC += 1;
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

	case 0x20: {
		PC += 1;
	} break;

		//LXI H, D16 Size: 3
	case 0x21: {
		uint16_t fstB = MEMORY[PC + 2];
		uint16_t sndB = MEMORY[PC + 1];
		if (debugPrintOn) std::cout << "LXI H, " << std::hex << (int)fstB << "" << (int)(sndB) << "\n";
		REGISTERS[5] = fstB;
		REGISTERS[6] = sndB;
		PC += 3;
	}break;

		//SHLD adr Size: 3
	case 0x22: {

	}break;

		//INX H Size: 1
	case 0x23: {
		if (debugPrintOn) std::cout << "INX H " << std::hex << (int)REGISTERS[5] << (int)REGISTERS[6] << " <- ";
		REGISTERS[6] == 0xff ? REGISTERS[6] = 0x00, REGISTERS[5] += 1 : REGISTERS[6] += 0x01;
		if (debugPrintOn) std::cout << std::hex << (int)REGISTERS[5] << (int)REGISTERS[6] << "\n";
		PC += 1;
	}break;

		//INR H Size: 1
	case 0x24: {

	}break;
	
	//DCR H Size: 1
	case 0x25: {

	}break;

	//MVI H, D8 Size: 2
	case 0x26: {
		if (debugPrintOn) std::cout << "MVI H, D8  C<- " << std::hex << (int)MEMORY[PC + 1] << "\n";
		REGISTERS[5] = MEMORY[PC + 1];
		PC += 2;
	}break;

	//DAA Size: 1
	case 0x27: {

	}break;

	//DAD H Size: 1
	case 0x29: {
		uint16_t HL = REGISTERS[6] << 8 | REGISTERS[5];
		cf = (HL >> 15); //me fijo si tiene carry
		if (debugPrintOn) std::cout << "ADD HL + HL <- " << std::hex << (HL + HL) << " CF: " << cf << "\n";
		PC += 1;
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
		uint16_t D16 = (MEMORY[PC + 2] << 8) | MEMORY[PC + 1];
		SP = D16;
		if (debugPrintOn) std::cout << "LXI SP, " << D16 << "\n";
		PC += 3;
	}break;

		//STA adr Size: 3
	case 0x32: {
		uint8_t fstB = MEMORY[PC + 2];
		uint8_t sndB = MEMORY[PC + 1];
		uint16_t adr = (fstB << 8) + sndB;
		MEMORY[adr] = REGISTERS[0];
		if (debugPrintOn) std::cout << "STA " << adr << "\n";
		PC += 3;

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
		if (debugPrintOn) std::cout << "MVI M, D8  B<- " << std::hex << (int)MEMORY[PC + 1] << "\n";
		uint16_t adr = (REGISTERS[5] << 8) + REGISTERS[6];
		MEMORY[adr] = MEMORY[PC + 1];
		PC += 2;
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
		if (debugPrintOn) std::cout << "INR A " << std::hex << (int)REGISTERS[0] << " <- ";
		REGISTERS[0] += 1;
		//Flags handling
		REGISTERS[0] & (0x1 << 7) ? sf = 1 : sf = 0;	//sign flag
		REGISTERS[0] == 0 ? zf = 1 : zf = 0;			//zero flag
		REGISTERS[0] % 2 == 0 ? pf = 1 : pf = 0;		//parity flag
		REGISTERS[0] & 0xfff ? cfa = 1 : cfa = 0;		//auxiliary carry flag


		if (debugPrintOn) std::cout << std::hex << (int)REGISTERS[0] << "\n";
		PC += 1;
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
		if (debugPrintOn) std::cout << "MOV L <- A" << std::hex << (int)MEMORY[PC + 1] << "\n";
		REGISTERS[6] = REGISTERS[0];
		PC += 1;
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
		uint8_t regH = REGISTERS[5];
		uint8_t regL = REGISTERS[6];
		uint16_t adr = (REGISTERS[5] << 8) + REGISTERS[6];
		MEMORY[adr]  = REGISTERS[0];
		if (debugPrintOn) std::cout << "MOV [" << std::hex << adr << "] <- " << (int)REGISTERS[0] << "rA" << "\n";
		PC += 1;
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
		if (debugPrintOn) std::cout << "MOV A, H " << std::hex << (int)REGISTERS[5] << "\n";
		REGISTERS[0] = REGISTERS[5];
		PC += 1;
	}break;

		//MOV A, L Size: 1
	case 0x7d: {
		if (debugPrintOn) std::cout << "MOV A, L " << std::hex << (int)REGISTERS[6] << "\n";
		REGISTERS[0] = REGISTERS[6];
		PC += 1;
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
		if (debugPrintOn) std::cout << "POP B" << std::endl;
		REGISTERS[2] = MEMORY[SP];
		REGISTERS[1] = MEMORY[SP + 1];
		SP += 2;
		PC += 1;
	}break;

		//JNZ adr Size: 3
	case 0xc2: {
		if(!zf){
		uint16_t fstB = MEMORY[PC + 1];
		uint16_t sndB = MEMORY[PC + 2];
		uint16_t adr = (sndB << 8) + fstB; //Little endian 
		if (debugPrintOn) std::cout << "JNZ " << adr << "\n";
		PC = adr;
		}
		else {
			if (debugPrintOn) std::cout << "JNZ " << "zf = 1, no jump" << "\n";
			PC += 3;
		}
	}break;

		//JMP adr Size: 3
	case 0xc3: {
		uint16_t fstB = MEMORY[PC + 1];
		uint16_t sndB = MEMORY[PC + 2];
		uint16_t adr = (sndB << 8) + fstB; //Little endian 
		if (debugPrintOn) std::cout << "JMP " << adr <<"\n";
		PC = adr;
	}break;

		//CNZ adr Size: 3
	case 0xc4: {

	}break;

		//PUSH B Size: 1
	case 0xc5: {
		if(debugPrintOn) std::cout << "PUSH B" << "\n";
		MEMORY[SP - 2] = REGISTERS[2];
		MEMORY[SP - 1] = REGISTERS[1];
		SP -= 2;
		PC += 1;
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
		PC = (MEMORY[SP+1]<<8) | MEMORY[SP+2];
		if (debugPrintOn) std::cout << "RET PC <- " << std::hex << PC << std::endl;
		SP += 2;
	}break;

		//JZ adr Size: 1
	case 0xca: {

	}break;

		//CZ adr Size: 3
	case 0xcc: {

	}break;

		//CALL adr Size: 3
	case 0xcd: {
		uint16_t adr = (MEMORY[PC + 2] << 8) | MEMORY[PC + 1];
		if (debugPrintOn) std::cout << "CALL " << adr << std::endl;
		SP--;
		MEMORY[SP] = (PC + 3);
		SP--;
		MEMORY[SP] = (PC + 3) >> 8;
		SP--;
		PC = adr;
		
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
		if (debugPrintOn) std::cout << "POP D" << std::endl;
		REGISTERS[4] = MEMORY[SP];
		REGISTERS[3] = MEMORY[SP + 1];
		SP += 2;
		PC += 1;
	}break;

		//JNC adr Size: 3
	case 0xd2: {

	}break;

		//OUT D8 Size: 2
	case 0xd3: {
		if(debugPrintOn) std::cout << "OUT, not implemented" << std::endl;
		PC += 2;
	}break;

		//CNC adr Size: 1
	case 0xd4: {
		if (debugPrintOn) std::cout << "PC: " << PC << " CNC adr" << "\n";
		if (!cf) {

		}

	}break;

		//PUSH D Size: 1
	case 0xd5: {
		if(debugPrintOn) std::cout << "PUSH D" << "\n";
		MEMORY[SP - 2] = REGISTERS[4];
		MEMORY[SP - 1] = REGISTERS[3];
		SP -= 2;
		PC += 1;
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
		if(debugPrintOn) std::cout << "POP H" << std::endl;
		REGISTERS[6] = MEMORY[SP];
		REGISTERS[5] = MEMORY[SP + 1];
		SP += 2;
		PC += 1;
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
		if(debugPrintOn) std::cout << "PUSH H" << std::endl;
		MEMORY[SP - 2] = REGISTERS[6];
		MEMORY[SP - 1] = REGISTERS[5];
		SP -= 2;
		PC += 1;
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
		if (debugPrintOn) std::cout << "XCHG: H <-> D, L <-> E" << "\n";
		uint8_t tempH = REGISTERS[5];
		uint8_t tempL = REGISTERS[6];
		REGISTERS[5] = REGISTERS[3];
		REGISTERS[6] = REGISTERS[4];
		REGISTERS[3] = tempH;
		REGISTERS[4] = tempL;
		PC += 1;
		
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
		if(debugPrintOn) std::cout << "CPI D8" << "\n";
		uint8_t data = MEMORY[PC + 1];
		uint8_t res = REGISTERS[0] - data;
		//flags
		zf = res == 0;	sf = (res & 0x80);	pf = res & 0x1;	cf = REGISTERS[0] < data; 
		PC += 2;
	}break;

		//RST 7 Size: 1
	case 0xff: {

	}break;
}


}