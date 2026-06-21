#include "labels_table.h"
#include <stdint.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#define MAX_LABELS 30

LabelsTable labels_table[MAX_LABELS] = {0};

void addLabel(const char *name, uint64_t address) {
    for (int i = 0; i < MAX_LABELS; i++) {
        if (labels_table[i].name[0] == '\0') { // check if empty.
            strncpy(labels_table[i].name, name, sizeof(labels_table[i].name) - 1);
            labels_table[i].name[sizeof(labels_table[i].name) - 1] = '\0'; // null terminator.
            labels_table[i].address = address;  
            return;
        } 
    }

    fprintf(stderr, "Error: insufficient space for label\n");
    exit(EXIT_FAILURE);
}

uint64_t getLabelAddress(const char *name) {
    for (int i = 0; i < MAX_LABELS; i++) {
        if (strcmp(labels_table[i].name, name) == 0) {
            return labels_table[i].address;
        }
    }

    fprintf(stderr, "Error: label '%s' not found\n", name);
    exit(EXIT_FAILURE);
}
