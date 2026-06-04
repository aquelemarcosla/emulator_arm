#ifndef BUILDERDPI_L_H
#define BUILDERDPI_L_H
#include "stdint.h"

uint32_t builderANDI(char *buffer, char **saveptr);
uint32_t builderORI(char *buffer, char **saveptr);
uint32_t builderXORI(char *buffer, char **saveptr);

#endif // BUILDERDPI_L_H