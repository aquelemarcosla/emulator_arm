#include "labels_table.h"
#include <stdint.h>
#include <string.h>
#define MAX_LABELS 20

const int labels_table_size = MAX_LABELS;

LabelsTable labels_table[MAX_LABELS] = {0};

void addLabel(const char *name, uint64_t address) {
    for (int i = 0; i < labels_table_size; i++) {
        if (labels_table[i].name[0] == '\0') { //verifica vazio.
            strncpy(labels_table[i].name, name, sizeof(labels_table[i].name) - 1);
            labels_table[i].name[sizeof(labels_table[i].name) - 1] = '\0'; //null final.
            labels_table[i].address = address;
            return;
        } 
    }
}

uint64_t getLabelAddress(const char *name) {
    for (int i = 0; i < labels_table_size; i++) {
        if (strcmp(labels_table[i].name, name) == 0) {
            return labels_table[i].address;
        }
    }
    return 0;
}
