#include "memory.h"
#include <stdint.h>

uint64_t mem_read(uint64_t address) {
    uint64_t result = 0;

    if (address + 7 >= MEM_SIZE) { // verifica se o endereço acessado mais alinhamento não ultrapassa o limite
        // limite
    }

    for (int i = 0; i <= 7; i++) {
        result |= (uint64_t)memory[address + i] << (i * 8); // cast para 64 bits antes do shift para não estourar o dado
    }
    return result;
}