#include <stdio.h>
#include "unity.h"
#include "../../cpu/cpu.h"
#include "../../encode/encode.h"

static void print_binary32(uint32_t value) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (value >> i) & 1u);

        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

void test_encode_MOVZ(void) {
    uint32_t result = encode("MOVZ X0, #100");

    // ADDI: bits [31:21] = 0x694, [20:5] = imm16, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x694u << 21) | (100u << 5) | 0u;

    printf("\n=== test_encode_MOVZ ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_MOVN(void) {
    uint32_t result = encode("MOVN X0, #100");

    // ADDI: bits [31:21] = 0x494, [20:5] = imm16, [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x494u << 21) | (100u << 5) | 0u;

    printf("\n=== test_encode_MOVN ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}
