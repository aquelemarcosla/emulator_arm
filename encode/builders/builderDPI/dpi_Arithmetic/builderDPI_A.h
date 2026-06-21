#ifndef BUILDER_DPI_A_H
#define BUILDER_DPI_A_H
#include "stdint.h"

uint32_t builderADDI(uint32_t value, char **saveptr);
uint32_t builderSUBI(uint32_t value, char **saveptr);
uint32_t builderCMPI(uint32_t value, char **saveptr);

#endif
