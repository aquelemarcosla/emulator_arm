#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    uint64_t regs[32]; // 0 - 31
    uint64_t pc;  // Program Counter (reg 32)
    uint64_t sp;  // Registrador Stack Pointer (reg 33)
} CPU;

typedef struct { // struct da instrução
    uint8_t opcode;
    uint8_t type;
    uint8_t rd;
    uint8_t rn;  // R1
    uint8_t rm;  // R2
    int64_t imm;   // Imediatos com sinal para possiveis negativos
} instruction;

uint64_t reg_read(CPU *cpu, int reg);  // Leitura de registrador

void reg_write(CPU *cpu, int reg, uint64_t value);  //  Escrita de registrador

#endif