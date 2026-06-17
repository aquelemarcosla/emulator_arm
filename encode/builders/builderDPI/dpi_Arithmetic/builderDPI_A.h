#ifndef BUILDER_DPI_A_H
#define BUILDER_DPI_A_H
#include "stdint.h"

uint32_t builderADDI(uint32_t value, char **saveptr);
uint32_t builderSUBI(uint32_t value, char **saveptr);
uint32_t builderCMPI(uint32_t value, char **saveptr);

// Extrai registrador na tabela (X0-X31)
uint8_t find_register(char **saveptr);

// Extrai imediato no formato "#(número)" de até 12 bits
// Com carry on: rotaciona bits superiores se exceder 12 bits
uint16_t find_immediate(char **saveptr);

#endif
