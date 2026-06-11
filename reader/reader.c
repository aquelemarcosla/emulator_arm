#include "reader.h"
#include "string.h"
#include "opcode_table.h"
#include "encode.h"

int reader(char *instruction) {
    char *opcode = strtok(instruction, " ");
    if (opcode == NULL) {
        return 0; 
    }

    for (int i = 0; i < opcode_table_size; i++) {
        if (strcmp(opcode, opcode_table[i].mnemonic) == 0) {
            return 1;
        }
    }


}