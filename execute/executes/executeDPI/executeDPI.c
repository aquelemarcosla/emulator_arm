#include "executeDPI.h"

#include "execute/alu/alu.h"

void executeADDI(Instruction *instruction, CPU *cpu) {
    uint64_t regDest;
    uint64_t regSrc1 = reg_read(cpu, instruction->rn);
    uint64_t imm = instruction->imm;

    regDest = execute_alu(regSrc1, imm, ALU_ADD);
    reg_write(cpu, instruction->rd, regDest);

    cpu->pc += 4;
}

void executeSUBI(Instruction *instruction, CPU *cpu) {
    uint64_t regDest;
    uint64_t regSrc1 = reg_read(cpu, instruction->rn);
    uint64_t imm = instruction->imm;

    regDest = execute_alu(regSrc1, imm, ALU_SUB);
    reg_write(cpu, instruction->rd, regDest);

    cpu->pc += 4;

    if ((regDest >> 30) == 0x1) {
        cpu->nzcv = 8;
    }
}

void executeCMPI(Instruction *instruction, CPU *cpu) {

}

void executeANDI(Instruction *instruction, CPU *cpu) {

}

void executeORRI(Instruction *instruction, CPU *cpu) {

}

void executeEORI(Instruction *instruction, CPU *cpu) {

}

void executeMOVZ(Instruction *instruction, CPU *cpu) {

}

void executeMOVN(Instruction *instruction, CPU *cpu) {

}
