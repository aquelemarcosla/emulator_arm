#include "executeDPR.h"

#include "execute/alu/alu.h"

void executeADD(Instruction *instruction, CPU *cpu) {
    uint64_t rn_val = reg_read(cpu, instruction->rn);
    uint64_t rm_val = reg_read(cpu, instruction->rm);

    uint64_t result = execute_alu(rn_val, rm_val, ALU_ADD);

    reg_write(cpu, instruction->rd, result);
}

void executeSUB(Instruction *instruction, CPU *cpu) {
    uint64_t rn_val = reg_read(cpu, instruction->rn);
    uint64_t rm_val = reg_read(cpu, instruction->rm);

    uint64_t result = execute_alu(rn_val, rm_val, ALU_SUB);

    reg_write(cpu, instruction->rd, result);
}

void executeAND(Instruction *instruction, CPU *cpu) {
    uint64_t rn_val = reg_read(cpu, instruction->rn);
    uint64_t rm_val = reg_read(cpu, instruction->rm);

    uint64_t result = execute_alu(rn_val, rm_val, ALU_AND);

    reg_write(cpu, instruction->rd, result);
}

void executeORR(Instruction *instruction, CPU *cpu) {
    uint64_t rn_val = reg_read(cpu, instruction->rn);
    uint64_t rm_val = reg_read(cpu, instruction->rm);

    uint64_t result = execute_alu(rn_val, rm_val, ALU_ORR);

    reg_write(cpu, instruction->rd, result);
}

void executeEOR(Instruction *instruction, CPU *cpu) {
    uint64_t rn_val = reg_read(cpu, instruction->rn);
    uint64_t rm_val = reg_read(cpu, instruction->rm);

    uint64_t result = execute_alu(rn_val, rm_val, ALU_EOR);

    reg_write(cpu, instruction->rd, result);
}

void executeLSLV(Instruction *instruction, CPU *cpu) {
    uint64_t rn_val = reg_read(cpu, instruction->rn);
    uint64_t rm_val = reg_read(cpu, instruction->rm);

    uint64_t result = execute_alu(rn_val, rm_val, ALU_LSL);

    reg_write(cpu, instruction->rd, result);
}

void executeLSRV(Instruction *instruction, CPU *cpu) {
    uint64_t rn_val = reg_read(cpu, instruction->rn);
    uint64_t rm_val = reg_read(cpu, instruction->rm);

    uint64_t result = execute_alu(rn_val, rm_val, ALU_LSR);

    reg_write(cpu, instruction->rd, result);
}