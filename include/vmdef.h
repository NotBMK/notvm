#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using BYTE = unsigned char;
    using WORD = unsigned short;

    enum OpCode
    {
        LDA_IM = 0xA9, // Load Accumulator Immediate
        LDX_IM = 0xA2, // Load X Register Immediate
        LDY_IM = 0xA0, // Load Y Register Immediate
        STA_ZP = 0x85, // Store Accumulator Zero Page
        STX_ZP = 0x86, // Store X Register Zero Page
        STY_ZP = 0x84, // Store Y Register Zero Page
        LDA_ZP = 0xA5, // Load Accumulator Zero Page
        LDX_ZP = 0xA6, // Load X Register Zero Page
    };

} // namespace nvm


#endif