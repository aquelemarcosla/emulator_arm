#include "cpu.h"
#include "stdint.h"

void reg_write(CPU *cpu, int reg, uint64_t value) {  // Escrita registrador
    if (reg == 31) { // caso XZR
        return;
    } else if (reg == 32) {
        cpu->pc= value;
    } else if (reg == 33) {
        cpu->sp= value;
    }
    cpu->regs[reg] = value;
}

uint64_t reg_read(CPU *cpu, int reg) {  // Leitura Registrador
    if (reg == 31) { // caso XZR
        return 0;
    }
    return cpu->regs[reg];
}



