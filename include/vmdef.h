#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using BYTE = unsigned char;
    using WORD = unsigned short;

    enum Instruction
    {
        INST_LDA_IM = 0xA9, // Load Accumulator Immediate
        INST_LDA_ZP = 0xA5, // Load Accumulator Zero Page
        INST_LDA_ZPX = 0xB5, // Load Accumulator Zero Page,X
        INST_LDA_ABS = 0xAD,
        INST_LDA_ABSX = 0xBD,
        INST_LDA_ABSY = 0xB9,
        INST_LDA_IDX = 0xA1,
        INST_LDA_IDY = 0xB1,

        INST_JSR = 0x20, // Jump to Subroutine
    };

} // namespace nvm


#endif