#include "unity.h"

// Test CPU.
void test_reg_read_and_write(void);
void test_nzcv(void);

// Test encode Branch
void test_encode_BNE(void);
void test_encode_BEQ(void);
void test_encode_Branch(void);

// Test encode DPI_A
void test_encode_ADDI(void);
void test_encode_SUBI(void);
void test_encode_CMPI(void);
void test_encode_ANDI(void);
void test_encode_ORRI(void);
void test_encode_EORI(void);
void test_encode_MOVZ(void);
void test_encode_MOVN(void);

void setUp(void){}
void tearDown(void){}

int main(void) {
    UNITY_BEGIN();
    RUN_TEST(test_encode_MOVN);
    UNITY_END();
}
