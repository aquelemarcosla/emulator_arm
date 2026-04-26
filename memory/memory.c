#include "memory.h"
#include <stdint.h>

uint8_t memory[MEM_SIZE]; // memoria declarada

uint64_t mem_read(uint64_t address) {
    uint64_t result = 0;

    if (address + 7 >= MEM_SIZE) { // verifica se o endereço acessado mais alinhamento não ultrapassa o limite
        // limite
    }

    for (int i = 0; i <= 7; i++) {  
        result |= (uint64_t)memory[address + i] << (i * 8); // Cast para 64 bits antes do shift para não estourar o uint*_t
    }
    return result;
}

void mem_write(uint64_t address, uint64_t data) {
    if (address + 7 >= MEM_SIZE) {
        // limite
    }

    for (int i = 0; i <= 7; i++) {
        memory[address + i] = data >> (i * 8);
    }
}