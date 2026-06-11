#include "reader.h"
#include "string.h"
#include "opcode_table.h"
#include "encode.h"
#include "cpu/cpu.h"

int reader(CPU *cpu, char *text) {
    char *opcode = strtok(text, " ");
    if (opcode == NULL) {
        return 1; 
    }

    for (int i = 0; i < opcode_table_size; i++) {
        if (strcmp(opcode, opcode_table[i].mnemonic) == 0) {
            return 2;
        }
    }

    return 0;
}