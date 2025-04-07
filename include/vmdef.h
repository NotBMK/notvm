#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using BYTE = unsigned char;
    using WORD = unsigned short;
    using U32 = unsigned int;
    using S32 = signed int;

    enum Constant
    {
        PAGE_SIZE = 256, // size of per page
        MAXN_PAGE = 256, // amount of pages
    };

       
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

        LDB,
        LDC,

        JSR,
    };
} // namespace nvm


#endif