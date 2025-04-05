#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using BYTE = unsigned char;
    using WORD = unsigned short;

    enum Instruction
    {
        LDA_IM = 0xA9, // Load Accumulator Immediate
        LDA_ZP = 0xA5, // 
    };

} // namespace nvm


#endif