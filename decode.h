#ifndef DECODE_H
#define DECODE_H
#include "cpu.h"

instruction decode(uint32_t data); //função que retorna a instrução decodificada
instruction buildDPR(uint32_t data);
instruction buildDPI(uint32_t data);
instruction buildB(uint32_t data);
instruction buildM(uint32_t data);

#endif