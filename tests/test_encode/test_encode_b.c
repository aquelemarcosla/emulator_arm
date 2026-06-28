#include <string.h>
#include "unity.h"
#include "../../cpu/cpu.h"
#include "../../encode/encode.h"
#include "../../cpu/labels_table/labels_table.h"
#include "cpu/program_table/program_table.h"

static void print_binary32(uint32_t value) {
    for (int i = 31; i >= 0; i--) {
        printf("%u", (value >> i) & 1u);

        if (i % 4 == 0)
            printf(" ");
    }
    printf("\n");
}

void test_encode_Branch(void) {

    // Add 0 (32bits) to program_table to create PC.
    addInstruction(0);

    uint64_t currentPC = getLastPC();
    uint64_t targetLabel = 12;
    int64_t targetOffset;
    addLabel("label", 12);

    targetOffset = (targetLabel - currentPC) / 4;

    uint32_t result = encode("B label");

    uint32_t expected = (5u << 26) | targetOffset; // Expected bits

    printf("\n=== test_encode_branch ===\n");

    printf("Result   : 0x%08X\n", result);
    print_binary32(result);

    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_BNE(void) {

    // Add 0 (32bits) to program_table to create PC.
    addInstruction(0);

    uint64_t currentPC = getLastPC();
    uint64_t targetLabel = 12;
    int64_t targetOffset;
    addLabel("label", 12);

    targetOffset = (targetLabel - currentPC) / 4;

    uint32_t result = encode("BNE label");

    uint32_t expected = (0x54u << 24) | (targetOffset << 5) | (0u << 4) | 1; // Expected bits

    printf("\n=== test_encode_BNE ===\n");

    printf("Result   : 0x%08X\n", result);
    print_binary32(result);

    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}

void test_encode_BEQ(void) {

    // Add 0 (32bits) to program_table to create PC.
    addInstruction(0);

    uint64_t currentPC = getLastPC();
    uint64_t targetLabel = 12;
    int64_t targetOffset;
    addLabel("label", 12);

    targetOffset = (targetLabel - currentPC) / 4;

    uint32_t result = encode("BEQ label");

    uint32_t expected = (0x54u << 24) | (targetOffset << 5) | (0u << 4) | 0u; // Expected bits

    printf("\n=== test_encode_BEQ ===\n");

    printf("Result   : 0x%08X\n", result);
    print_binary32(result);

    printf("Expected : 0x%08X\n", expected);
    print_binary32(expected);

    TEST_ASSERT_EQUAL_HEX32(expected, result);
}


