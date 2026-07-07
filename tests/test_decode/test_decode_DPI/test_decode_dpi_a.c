#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"
#include "../../../decode/decode.h"

static void print_binary32(uint32_t value) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (value >> i) & 1u);

        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

static void print_bits_with_value(uint64_t value, int width, int is_signed) {
    uint64_t mask = (width == 64) ? ~0ULL : ((1ULL << width) - 1ULL);
    uint64_t v = value & mask;
    for (int i = width - 1; i >= 0; i--) {
        printf("%u", (unsigned)((v >> i) & 1u));
        if (i % 4 == 0 && i != 0)
            printf(" ");
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

void test_decode_ADDI(void) {
    uint32_t encoded = encode("ADDI X0, X1, #100");
    Instruction instruction = decode(encoded);

    printf("\n=== test_decode_ADDI ===\n");
    printf("Encoded  : 0x%08X\n", encoded);
    print_binary32(encoded);
    printf("type     : ");
    print_bits_with_value(instruction.type, 4, 0);
    printf("rd       : ");
    print_bits_with_value(instruction.rd, 5, 0);
    printf("rn       : ");
    print_bits_with_value(instruction.rn, 5, 0);
    printf("rm       : ");
    print_bits_with_value(instruction.rm, 5, 0);
    printf("imm      : ");
    print_bits_with_value((uint64_t)instruction.imm, 12, 1);

    TEST_ASSERT_EQUAL_UINT8(8, instruction.type);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rd);
    TEST_ASSERT_EQUAL_UINT8(1, instruction.rn);
    TEST_ASSERT_EQUAL_UINT8(0, instruction.rm);
    TEST_ASSERT_EQUAL_INT64(100, instruction.imm);
}
