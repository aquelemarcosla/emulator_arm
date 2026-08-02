#ifndef EMULATOR_ARM_EXECUTEM_H
#define EMULATOR_ARM_EXECUTEM_H
#include "cpu/cpu.h"

void executeSTR(Instruction *instruction, CPU *cpu);
void executeLDR(Instruction *instruction, CPU *cpu);

#endif //EMULATOR_ARM_EXECUTEM_H
