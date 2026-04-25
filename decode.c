#include "cpu.h"
#include "stdint.h"
#include "decode.h"
#define GET_BITS(data, shift, mask) (((data) >> (shift)) & (mask)) // Macro para desempacotar o dado bruto

instruction buildInsR(uint32_t data) {
    instruction inst;


}

instruction decode(uint32_t data) {
    instruction inst;
    uint16_t testIns = GET_BITS(data, 24, 0xFF); // Mascara e obtensão do opcode

    switch (testIns) {
        case 0:  // type R
            return buildInsR(data);
        case 1:  // type I

    }
}