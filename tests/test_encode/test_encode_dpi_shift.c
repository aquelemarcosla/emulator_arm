#include <stdio.h>
#include <string.h>
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

void test_encode_LSL(void) {
    uint32_t result = encode("LSL X0, X1, #5");

    uint32_t immr = (64u - 5u) % 64u; // 59
    uint32_t imms = 63u - 5u;         // 58
    uint32_t expected = (0x34Du << 22) | (immr << 16) | (imms << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_LSL ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_LSR(void) {
    uint32_t result = encode("LSR X2, X3, #10");
    
    uint32_t immr = 10u;
    uint32_t imms = 63u;
    uint32_t expected = (0x34Du << 22) | (immr << 16) | (imms << 10) | (3u << 5) | 2u;

    printf("\n=== test_encode_LSR ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}
