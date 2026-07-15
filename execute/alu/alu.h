#ifndef EMULATOR_ARM_ALU_H
#define EMULATOR_ARM_ALU_H

#include "cpu/cpu.h"

uint64_t execute_alu(CPU *cpu, uint64_t op1, uint64_t op2, int type_op);

#endif //EMULATOR_ARM_ALU_H
