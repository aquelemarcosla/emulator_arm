#include "cpu.h"
#include "stdint.h"

void reg_write(CPU *cpu, int reg, uint64_t value) {
    cpu->regs[reg] = value;
}

uint64_t reg_read(CPU *cpu, int reg) {
    return cpu->regs[reg];
}



