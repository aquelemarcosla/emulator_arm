#ifndef LABELS_TABLE_H
#define LABELS_TABLE_H
#include "stdint.h"

typedef struct {
    char name[32];
    uint64_t address;
} LabelsTable;

void addLabel(const char *name, uint64_t address);
uint64_t getLabelAddress(const char *name);

#endif // LABELS_TABLE_H