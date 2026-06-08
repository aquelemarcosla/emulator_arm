#ifndef REGISTERS_TABLE_H
#define REGISTERS_TABLE_H
#include "stdint.h"

typedef struct {
    char *mnemonic;
    uint16_t value;
} RegistersTable;

extern RegistersTable registers_table[];
extern const int registers_table_size;

#endif // REGISTERS_TABLE_H