#include <stdio.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

static void print_binary32(uint32_t value) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (value >> i) & 1u);
        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

void test_encode_m_LDR(void) {
    uint32_t result = encode("LDR X0, [X1, #8]");

    // LDR: bits [31:22] = 0x3E5, [21:10] = imm12 (imm/8), [9:5] = rn, [4:0] = rd
    uint32_t expected = (0x3E5u << 22) | (1u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_m_LDR ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}
