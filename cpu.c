#include "cpu.h"
#include "stdint.h"

void reg_write(CPU *cpu, int reg, uint64_t value) {  // Escrita registrador
    if (reg == 31) { // caso XZR
        return;
    }
    cpu->regs[reg] = value;
}

uint64_t reg_read(CPU *cpu, int reg) {  // Leitura Registrador
    if (reg == 31) { // caso XZR
        return 0;
    }
    return cpu->regs[reg];
}



