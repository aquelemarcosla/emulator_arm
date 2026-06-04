#include "opcode_table.h"
#include <stdint.h>
#include "../builders/builders.h"

OpcodeTable opcode_table[] = {
    {"ADDI", 0x244, &builderADDI},
    {"SUBI", 0x344, &builderSUBI},
    {"CMPI", 0x3C4, &builderCMPI},
};

const int opcode_table_size = sizeof(opcode_table) / sizeof(OpcodeTable);
