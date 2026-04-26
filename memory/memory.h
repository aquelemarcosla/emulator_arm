#ifndef MEMORY_H
#define MEMORY_H
#include <stdint.h>

#define MEM_SIZE 131072

extern uint8_t memory[MEM_SIZE]; // extern para memory só existir em memory.c

uint64_t mem_read(uint64_t address);

void mem_write(uint64_t address, uint64_t data);

#endif

