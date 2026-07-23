#ifndef EMULATOR_ARM_EXECUTEB_H
#define EMULATOR_ARM_EXECUTEB_H
#include "cpu/cpu.h"

void executeB(Instruction *instruction, CPU *cpu);
void executeBL(Instruction *instruction, CPU *cpu);
void executeRET(Instruction *instruction, CPU *cpu);
void executeBEQ(Instruction *instruction, CPU *cpu);
void executeBNE(Instruction *instruction, CPU *cpu);

#endif //EMULATOR_ARM_EXECUTEB_H
