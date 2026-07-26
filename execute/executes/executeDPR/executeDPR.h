#ifndef EMULATOR_ARM_EXECUTEDPR_H
#define EMULATOR_ARM_EXECUTEDPR_H
#include "cpu/cpu.h"

void executeADD(Instruction *instruction, CPU *cpu);
void executeSUB(Instruction *instruction, CPU *cpu);
void executeAND(Instruction *instruction, CPU *cpu);
void executeORR(Instruction *instruction, CPU *cpu);
void executeEOR(Instruction *instruction, CPU *cpu);
void executeLSLV(Instruction *instruction, CPU *cpu);
void executeLSRV(Instruction *instruction, CPU *cpu);

#endif //EMULATOR_ARM_EXECUTEDPR_H
