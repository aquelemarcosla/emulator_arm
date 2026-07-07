#ifndef PRINT_UTILS_H
#define PRINT_UTILS_H

#include <stdint.h>

void print_binary32(uint32_t value);
void print_bits_with_value(uint64_t value, int width, int is_signed);

#endif /* PRINT_UTILS_H */
