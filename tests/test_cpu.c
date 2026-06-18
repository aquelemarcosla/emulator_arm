#include <string.h>
#include "unity.h"
#include "../cpu/cpu.h"

void test_reg_read_and_write(void) {
    // Clean CPU
    CPU cpu;
    memset(&cpu, 0, sizeof(cpu));
    int MAX_REG = (sizeof(cpu.regs) / sizeof(cpu.regs[0])) - 1;
    uint64_t valueTest = 0x1234567890123456;

    // Testing read and write on general registers (XZR is not tested here)
    for (int i = 0; i <= (MAX_REG - 1); i++) {
        reg_write(&cpu, i, valueTest);
        TEST_ASSERT_EQUAL_UINT64(valueTest, reg_read(&cpu, i));
    }

    // XZR test (writes a value and must always return zero)
    reg_write(&cpu, 31, valueTest);
    TEST_ASSERT_EQUAL_UINT64(0, reg_read(&cpu, 31));

    // PC(32) and SP(33) test (read and write)
    for (int i = 32; i <= 33; i++) {
        reg_write(&cpu, i, valueTest);
        TEST_ASSERT_EQUAL_UINT64(valueTest, reg_read(&cpu, i));
    }

    // Index boundary test (read and write)
    reg_write(&cpu, -1, valueTest);  // Below the index
    TEST_ASSERT_EQUAL_UINT64(0, reg_read(&cpu, -1));
    reg_write(&cpu, 38, valueTest);  // Above the index
    TEST_ASSERT_EQUAL_UINT64(0, reg_read(&cpu, 38));
}

void test_nzcv(void) {
    CPU cpu;
    memset(&cpu, 0, sizeof(cpu));
    uint8_t nzcvValue = 0xFF;
    set_nzcv(&cpu, nzcvValue);
    TEST_ASSERT_EQUAL_UINT8(0xFF, get_nzcv(&cpu));
}
