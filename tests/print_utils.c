#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include "print_utils.h"

void print_binary32(uint32_t value) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (unsigned)((value >> i) & 1u));
        if (i % 4 == 0 && i != 0) printf(" ");
    }
    printf("\n");
}

void print_bits_with_value(uint64_t value, int width, int is_signed) {
    uint64_t mask = (width == 64) ? ~0ULL : ((1ULL << width) - 1ULL);
    uint64_t v = value & mask;
    for (int i = width - 1; i >= 0; i--) {
        printf("%u", (unsigned)((v >> i) & 1u));
        if (i % 4 == 0 && i != 0) printf(" ");
    }
    if (is_signed) {
        int64_t sval;
        if (width == 64)
            sval = (int64_t)v;
        else {
            uint64_t sign_bit = 1ULL << (width - 1);
            if (v & sign_bit)
                sval = (int64_t)(v | (~mask));
            else
                sval = (int64_t)v;
        }
        printf("  %lld\n", (long long)sval);
    } else {
        printf("  %llu\n", (unsigned long long)v);
    }
}
