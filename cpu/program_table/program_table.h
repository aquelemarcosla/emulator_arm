#ifndef PROGRAM_TABLE_H
#define PROGRAM_TABLE_H
#include <stdint.h>

typedef struct {
    uint32_t instruction;
    uint64_t program_counter;
} ProgramTableEntry;

void addInstruction(uint32_t instruction);
uint32_t getInstruction(uint64_t pc);
uint64_t getLastPC();

#endif // PROGRAM_TABLE_H