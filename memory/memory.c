#include "memory.h"

uint8_t memory[MEM_SIZE];  // Declared memory

uint64_t mem_read(uint64_t address) {
    uint64_t result = 0;

    if (address + 7 >= MEM_SIZE) {  // Check whether the 8-byte access is within bounds
        // Out of bounds.
    }

    for (int i = 0; i < 8; i++) {
        result |= (uint64_t)memory[address + i] << (i * 8);
    }

    return result;
}

void mem_write(uint64_t address, uint64_t data) {
    if (address + 7 >= MEM_SIZE) {
        // Out of bounds.
    }

    for (int i = 0; i < 8; i++) {
        memory[address + i] = (uint8_t)(data >> (i * 8));
    }
}
