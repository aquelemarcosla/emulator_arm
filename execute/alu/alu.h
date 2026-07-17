#ifndef EMULATOR_ARM_ALU_H
#define EMULATOR_ARM_ALU_H

#include "cpu/cpu.h"

typedef enum {
    ALU_ADD,
    ALU_SUB,
    ALU_AND,
    ALU_ORR,
    ALU_EOR,
    ALU_LSL,
    ALU_LSR
} TypeOp;

uint64_t execute_alu(CPU *cpu, uint64_t op1, uint64_t op2, TypeOp type_op);


#endif //EMULATOR_ARM_ALU_H
