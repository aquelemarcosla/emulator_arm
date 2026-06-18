#include <stdio.h>
#include "cpu/cpu.h"

int main(void) {
    // Init CPU.
    CPU cpu = {0};
    reg_write(&cpu, 33, 0x1FFFF);  // Setting SP.

    
    
}
