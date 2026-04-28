#include "cpu.h"
#include "stdint.h"

void reg_write(CPU *cpu, int reg, uint64_t value) {  // Escrita registrador
    if (reg == 31) { // caso XZR
        return;
    } else if (reg == 32) { // caso PC
        cpu->pc= value;
        return;
    } else if (reg == 33) { // caso SP
        cpu->sp= value;
        return;
    } else if (reg >= 34 || reg < 0 ) {
        return;
    }

    cpu->regs[reg] = value;
}

uint64_t reg_read(CPU *cpu, int reg) {  // Leitura Registrador
    if (reg == 31) { // caso XZR
        return 0;
    } else if (reg == 32) { // caso PC
        return cpu->pc;
    } else if (reg == 33) { // caso SP
        return cpu->sp;
    } else if (reg >= 34 || reg < 0 ) {
        return 0;
    }
    return cpu->regs[reg];
}



