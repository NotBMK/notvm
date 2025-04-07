#ifndef INC__VM_OP_CODES__H
#define INC__VM_OP_CODES__H

#include <vmdef.h>

namespace nvm
{
    enum Instruction
    {
        LDA_IMM = 0xA9,
        LDA_ZPG = 0xA5,
        LDA_ZPX = 0xB5,
        LDA_ABS = 0xAD,
        LDA_ABX = 0xBD,
        LDA_ABY = 0xB9,
        LDA_INX = 0xA1,
        LDA_INY = 0xB1,

        LDX_IMM = 0xA2,
        LDX_ZPG = 0xA6,
        LDX_ZPY = 0xB6,
        LDX_ABS = 0xAE,
        LDX_ABY = 0xBE,

        LDY_IMM = 0xA0,
        LDY_ZPG = 0xA4,
        LDY_ZPX = 0xB4,
        LDY_ABS = 0xAC,
        LDY_ABX = 0xBC,

        JSR,
    };
} // namespace nvm

#endif