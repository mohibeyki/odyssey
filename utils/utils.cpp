//
//  utils.cpp
//  odyssey
//
//  Created by Mohi Beyki on 11/12/17.
//  Copyright © 2017 Mohi Beyki. All rights reserved.
//

#include <cstdint>
#include <cpuid.h>
#include "utils.h"

void CPU_ID(std::uint32_t INFO[], std::uint32_t LEAF, std::uint32_t SUBLEAF) {
    __cpuid_count(LEAF, SUBLEAF, INFO[0], INFO[1], INFO[2], INFO[3]);
}

int GET_CPU() {
    int CPU;
    uint32_t CPUInfo[4];
    CPU_ID(CPUInfo, 1, 0);
    if ( (CPUInfo[3] & (1 << 9)) == 0) {
        CPU = -1;
    }
    else {
        CPU = (unsigned)CPUInfo[1] >> 24;
    }
    if (CPU < 0) CPU = 0;
    return CPU;
}
