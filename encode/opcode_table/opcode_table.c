#include "opcode_table.h"
#include "stdint.h"

OpcodeTable opcode_table[] = {
    {"ADD", 0x244},
    {"SUB", 0x1A00},
    {"MOV", 0x1000},
    {"CMP", 0x1400}
};

const int opcode_table_size = sizeof(opcode_table) / sizeof(OpcodeTable);
