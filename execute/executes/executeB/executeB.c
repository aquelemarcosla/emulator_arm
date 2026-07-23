#include "executeB.h"

void executeB(Instruction *instruction, CPU *cpu) {
    uint64_t labelAddress = instruction->imm;

    cpu->pc = labelAddress;
}

void executeBL(Instruction *instruction, CPU *cpu) {
    uint64_t labelAddress = instruction->imm;
    uint64_t actualAddress = (cpu->pc + 4);

    reg_write(cpu, 30, actualAddress);

    cpu->pc = labelAddress;
}

void executeRET(Instruction *instruction, CPU *cpu) {
    uint64_t returnAddress = reg_read(cpu, (instruction->rn));

    cpu->pc = returnAddress;
}

void executeBEQ(Instruction *instruction, CPU *cpu) {
    uint8_t getZero = (((cpu->nzcv) >> 2) & 1);

    if (getZero == 1) {
        cpu->pc = instruction->imm;
    }
}

void executeBNE(Instruction *instruction, CPU *cpu) {
    uint8_t getZero = (((cpu->nzcv) >> 2) & 1);

    if (getZero == 0) {
        cpu->pc = instruction->imm;
    }
}
