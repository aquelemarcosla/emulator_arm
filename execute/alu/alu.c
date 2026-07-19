#include "alu.h"
#include "cpu/cpu.h"

uint64_t execute_alu(uint64_t op1, uint64_t op2, TypeOp type_op) {
    uint64_t result = 0;

    switch (type_op) {
        case ALU_ADD: result = op1 + op2; break;
        case ALU_SUB: result = op1 - op2; break;
        case ALU_AND: result = op1 & op2; break;
        case ALU_ORR: result = op1 | op2; break;
        case ALU_EOR: result = op1 ^ op2; break;
        case ALU_LSL: result = op1 << op2; break;
        case ALU_LSR: result = op1 >> op2; break;
        default: break;
    }

    return result;
}

