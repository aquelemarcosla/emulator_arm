#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    uint64_t regs[32];  // 0 - 31
    uint64_t pc;        // Program Counter (reg 32)
    uint64_t sp;        // Stack Pointer (reg 33)
    uint8_t nzcv;       // NZCV flags
} CPU;

typedef struct {  // instruction struct
    uint8_t type;
    uint8_t rd;
    uint8_t rn;    // R1
    uint8_t rm;    // R2
    int64_t imm;   // Signed immediates for possible negative values
} Instruction;

uint8_t get_nzcv(CPU *cpu);

void set_nzcv(CPU *cpu, uint8_t nzcv);

uint64_t reg_read(CPU *cpu, int reg);  // Register read

void reg_write(CPU *cpu, int reg, uint64_t value);  // Register write

#endif
