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
        INST_LDA_ZPX = 0xB5,

        INST_JSR = 0x20, // Jump to Subroutine
    };

} // namespace nvm


#endif