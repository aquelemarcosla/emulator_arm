#include <string.h>
#include "unity.h"
#include "../cpu/cpu.h"

void test_reg_write(void) {
    //  CPU LIMPA
    CPU cpu;
    memset(&cpu, 0, sizeof(cpu));

    reg_write(&cpu, 0, 0x1234567890123456);

    TEST_ASSERT_EQUAL_UINT64(0x1234567890123456, reg_read(&cpu, 0));
}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_reg_write);
    return UNITY_END();
}

void setUp(void) {}
void tearDown(void) {}