#ifndef BUILDER_DPI_A_H
#define BUILDER_DPI_A_H
#include "stdint.h"

uint32_t builderADDI(uint32_t value, char **saveptr);
uint32_t builderSUBI(uint32_t value, char **saveptr);
uint32_t builderCMPI(uint32_t value, char **saveptr);

// Extracts the register from the table (X0-X31)
uint8_t find_register(char **saveptr);

// Extracts an immediate in the form "#(number)" up to 12 bits
// With carry-over: rotates upper bits if it exceeds 12 bits
uint16_t find_immediate(char **saveptr);

#endif
