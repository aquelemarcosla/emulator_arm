#ifndef ENCODE_OPCODE_TABLE_H
#define ENCODE_OPCODE_TABLE_H
#include "stdint.h"

typedef struct {
    char *mnemonic;
    uint16_t value;
    uint32_t (*builder)(char *, char **); // (buffer, saveptr)
} OpcodeTable;

extern OpcodeTable opcode_table[];
extern const int opcode_table_size;

#endif