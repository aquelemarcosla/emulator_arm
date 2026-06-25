#include "reader.h"
#include "string.h"
#include "encode/opcode_table/opcode_table.h"
#include "encode/encode.h"
#include "cpu/program_table/program_table.h"
#include "cpu/labels_table/labels_table.h"

int reader(char *text) {
    // Verify null.
    if (text == NULL) {
        return 0;
    }

    // Verify if have ':'.
    char *label = strchr(text, ':');

    if (label != NULL){
        *label = '\0'; 

        addLabel(text, getLastPC());

        return 0;
    }

    // Copy text to new buffer and alocate \0.
    char text_copy[64];
    strncpy(text_copy, text, sizeof(text_copy) - 1);
    text_copy[sizeof(text_copy) - 1] = '\0'; 

    // Get opcode string.
    char *opcode = strtok(text, " \t\r\n");

    if (opcode == NULL) {
        return 0;
    }

    for (int i = 0; i < opcode_table_size; i++) {
        if (strcmp(opcode, opcode_table[i].mnemonic) == 0) {
            addInstruction(encode(text_copy));
            return 0;
        }
    }

    return 0;
}