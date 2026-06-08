#include "opcode_table.h"
#include <stdint.h>
#include "../builders/builders.h"

OpcodeTable opcode_table[] = {
    // DPI
    {"ADDI", 0x244, &builderADDI},
    {"SUBI", 0x344, &builderSUBI},
    {"CMPI", 0x3C4, &builderCMPI},
    {"ANDI", 0x124, &builderANDI},
    {"ORRI", 0x164, &builderORRI},
    {"EORI", 0x1A4, &builderEORI},
    {"MOVZ", 0x694, &builderMOVZ},
    {"MOVN", 0x494, &builderMOVN},
    {"LSL", 0x34D, &builderUBFM},
    {"LSR", 0x34D, &builderUBFM},
    // DPR
    {"ADD", 0x458, &builderADD},
    {"SUB", 0x658, &builderSUB},
    {"AND", 0x450, &builderAND},
    {"ORR", 0x550, &builderORR},
    {"EOR", 0x650, &builderEOR},
    {"LSLV", 0x4D6, &builderLSLV},
    {"LSRV", 0x4D6, &builderLSRV},
};

const int opcode_table_size = sizeof(opcode_table) / sizeof(OpcodeTable);
