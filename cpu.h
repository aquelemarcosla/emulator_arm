#ifndef CPU_H
#define CPU_H

#include <stdint.h>

typedef struct {
    uint64_t regs[32]; // 32 registradores de 64 bits
    uint64_t pc;  // Registrador Program Counter
    uint64_t sp;  // Registrador Stack Pointer
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