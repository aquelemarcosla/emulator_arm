#ifndef EMULATOR_ARM_EXECUTEDPI_H
#define EMULATOR_ARM_EXECUTEDPI_H
#include "cpu/cpu.h"

void executeADDI(Instruction *instruction, CPU *cpu);
void executeSUBI(Instruction *instruction, CPU *cpu);
void executeCMPI(Instruction *instruction, CPU *cpu);
void executeANDI(Instruction *instruction, CPU *cpu);
void executeORRI(Instruction *instruction, CPU *cpu);
void executeEORI(Instruction *instruction, CPU *cpu);
void executeMOVZ(Instruction *instruction, CPU *cpu);
void executeMOVN(Instruction *instruction, CPU *cpu);

#endif //EMULATOR_ARM_EXECUTEDPI_H
