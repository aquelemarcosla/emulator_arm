#ifndef ENCODE_OPCODE_TABLE_H
#define ENCODE_OPCODE_TABLE_H
#include "stdint.h"

typedef struct {
    char *mnemonic;
    uint16_t opcode;
} OpcodeTable;

extern OpcodeTable opcode_table[];
extern const int opcode_table_size;

#endif