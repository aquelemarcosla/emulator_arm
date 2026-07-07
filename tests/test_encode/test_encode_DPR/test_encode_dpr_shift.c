#include <stdio.h>
#include <string.h>
#include "unity.h"
#include "../../../cpu/cpu.h"
#include "../../../encode/encode.h"

#include "../../print_utils.h"

void test_encode_dpr_LSLV(void) {
    uint32_t result = encode("LSLV X0, X1, X2");

    uint32_t expected = (0x4D6u << 21) | (2u << 16) | (8u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_dpr_LSLV ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_dpr_LSRV(void) {
    uint32_t result = encode("LSRV X0, X1, X2");

    uint32_t expected = (0x4D6u << 21) | (2u << 16) | (9u << 10) | (1u << 5) | 0u;

    printf("\n=== test_encode_dpr_LSRV ===\n");
    printf("Result   : 0x%08X\n", result);
    print_binary32(result);
    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}
