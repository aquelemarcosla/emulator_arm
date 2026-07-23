#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    uint64_t regs[31];  // 0 - 31
    uint64_t pc;        // Program Counter (reg 32)
    uint64_t sp;        // Stack Pointer (reg 33)
    uint8_t nzcv;       // NZCV flags
} CPU;

typedef struct {  // instruction struct
    uint64_t opcode;
    uint8_t rd;
    uint8_t rn;    // R1
    uint8_t rm;    // R2
    int64_t imm;   // Signed immediates for possible negative values
} Instruction;

uint64_t reg_read(CPU *cpu, int reg);  // Register read

void reg_write(CPU *cpu, int reg, uint64_t value);  // Register write

#endif
