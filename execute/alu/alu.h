#ifndef EMULADOR_ARM_ALU_H
#define EMULADOR_ARM_ALU_H

#include "cpu/cpu.h"

uint64_t
execute_alu(CPU *cpu, uint64_t op1, uint64_t op2, int type_op);

#endif //EMULADOR_ARM_ALU_H
