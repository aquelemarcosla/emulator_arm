#include "stdint.h"
#include "encode.h"

uint32_t encode(const char *instruction) {
    if (instruction == NULL){
        return 0;
    }

    char *saveptr;
    const char *delimitadores = " ,";

    char buffer[128];

    // instruction para buffer.
    strncpy(buffer, instruction, sizeof(buffer) - 1);

    // Null no final.
    buffer[sizeof(buffer) - 1] = '\0';

}