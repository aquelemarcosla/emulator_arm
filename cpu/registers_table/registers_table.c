#include "registers_table.h"
#include <stdint.h>

RegistersTable registers_table[] = {
    {"X0",  0x0},
    {"X1",  0x1},
    {"X2",  0x2},
    {"X3",  0x3},
    {"X4",  0x4},
    {"X5",  0x5},
    {"X6",  0x6},
    {"X7",  0x7},
    {"X8",  0x8},
    {"X9",  0x9},
    {"X10", 0xA},
    {"X11", 0xB},
    {"X12", 0xC},
    {"X13", 0xD},
    {"X14", 0xE},
    {"X15", 0xF},
    {"X16", 0x10},
    {"X17", 0x11},
    {"X18", 0x12},
    {"X19", 0x13},
    {"X20", 0x14},
    {"X21", 0x15},
    {"X22", 0x16},
    {"X23", 0x17},
    {"X24", 0x18},
    {"X25", 0x19},
    {"X26", 0x1A},
    {"X27", 0x1B},
    {"X28", 0x1C},
    {"X29", 0x1D},
    {"X30", 0x1E},
    {"X31",  0x1F},
};

const int registers_table_size = sizeof(registers_table) / sizeof(RegistersTable);
