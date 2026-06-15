#include "program_table.h"
#include "stdint.h"

ProgramTableEntry program_table[1024]; 
static uint64_t instruction_count = 0;

void addInstruction(uint32_t instruction) {
    if (instruction_count < 1024) {
        program_table[instruction_count].instruction = instruction;
        program_table[instruction_count].program_counter = instruction_count * 4;
        instruction_count++;
    }
}

uint32_t getInstruction(uint64_t pc) {
    if (pc < instruction_count * 4) {
        return program_table[pc / 4].instruction;
    }
    return 0;
}

uint64_t getLastPC() {
    return instruction_count * 4;
}