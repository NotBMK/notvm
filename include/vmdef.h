#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using BYTE = unsigned char;
    using WORD = unsigned short;

    enum Instruction
    {
        // LDA - Load Accumulator
        INST_LDA_IM = 0xA9, // Load Accumulator Immediate
        INST_LDA_ZP = 0xA5, // Load Accumulator Zero Page
        INST_LDA_ZPX = 0xB5, // Load Accumulator Zero Page,X
        INST_LDA_ABS = 0xAD,
        INST_LDA_ABSX = 0xBD,
        INST_LDA_ABSY = 0xB9,
        INST_LDA_INDX = 0xA1,
        INST_LDA_INDY = 0xB1,

        // LDX - Load X Register
        INST_LDX_IM = 0xA2, // Load X Register Immediate
        INST_LDX_ZP = 0xA6, // Load X Register Zero Page
        INST_LDX_ZPY = 0xB6, // Load X Register Zero Page,Y
        INST_LDX_ABS = 0xAE,
        INST_LDX_ABSY = 0xBE,

        // LDY - Load Y Register
        INST_LDY_IM = 0xA0, // Load Y Register Immediate
        INST_LDY_ZP = 0xA4, // Load Y Register Zero Page
        INST_LDY_ZPX = 0xB4, // Load Y Register Zero Page,Y
        INST_LDY_ABS = 0xAC,
        INST_LDY_ABSX = 0xBC,

        INST_JSR = 0x20, // Jump to Subroutine
    };


} // namespace nvm


#endif