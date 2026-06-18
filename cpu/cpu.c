#include "cpu.h"
#include <stdint.h>

void reg_write(CPU *cpu, int reg, uint64_t value) {  // Register write
    if (reg == 31) {  // XZR case
        return;
    }

    if (reg == 32) {  // PC case
        cpu->pc = value;
        return;
    }

    if (reg == 33) {  // SP case
        cpu->sp = value;
        return;
    }

    if (reg < 0 || reg >= 34) {
        return;
    }

    cpu->regs[reg] = value;
}

uint64_t reg_read(CPU *cpu, int reg) {  // Register read
    if (reg == 31) {  // XZR case
        return 0;
    }

    if (reg == 32) {  // PC case
        return cpu->pc;
    }

    if (reg == 33) {  // SP case
        return cpu->sp;
    }

    if (reg < 0 || reg >= 34) {
        return 0;
    }

    return cpu->regs[reg];
}

uint8_t get_nzcv(CPU *cpu) {
    return cpu->nzcv;
}

void set_nzcv(CPU *cpu, uint8_t nzcv) {
    cpu->nzcv = nzcv;
}
