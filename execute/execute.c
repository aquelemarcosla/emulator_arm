#include "cpu/cpu.h"
#include "executes/executeB/executeB.h"
#include "executes/executeDPI/executeDPI.h"

void execute(Instruction *instruction, CPU *cpu) {

    switch (instruction->opcode) {
        case 0x244:
            return executeADDI(instruction, cpu);
        case 0x344:
            return executeSUBI(instruction, cpu);
        case 0x3C4:
            return executeCMPI(instruction, cpu);
        case 0x124:
            return executeANDI(instruction, cpu);
        case 0x164:
            return executeORRI(instruction, cpu);
        case 0x1A4:
            return executeEORI(instruction, cpu);
        case 0x694:
            return executeMOVZ(instruction, cpu);
        case 0x494:
            return executeMOVN(instruction, cpu);
        case 0x5:
            return executeB(instruction,cpu);
        case 0x25:
            return executeBL(instruction,cpu);
        case 0xD6BE03C0:
            return executeRET(instruction, cpu);
        case 0x54:
            return executeBEQ(instruction, cpu);
        case 0x55:
            return executeBNE(instruction, cpu);
        default:
            return;
    }

}
