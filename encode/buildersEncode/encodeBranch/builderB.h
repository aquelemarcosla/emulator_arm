#ifndef BUILDERB_H
#define BUILDERB_H
#include "stdint.h"

uint32_t builderB(uint32_t value, char **saveptr);
uint32_t builderBL(uint32_t value, char **saveptr);
uint32_t builderRET(uint32_t value, char **saveptr);
uint32_t builderBEQ(uint32_t value, char **saveptr);
uint32_t builderBNE(uint32_t value, char **saveptr);

#endif // BUILDERB_H
