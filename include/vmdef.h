#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using U08 = unsigned char;
    using U16 = unsigned short;
    using U32 = unsigned int;
    using S08 = signed char;
    using S16 = signed short;
    using S32 = signed int;

    enum Constant
    {
        PAGE_SIZE = 256, // size of per page
        MAXN_PAGE = 256, // amount of pages
    };

    union Byte
    {
        U08 all;
        struct
        {
            U08 b00:1; U08 b01:1; U08 b02:1; U08 b03:1;
            U08 b04:1; U08 b05:1; U08 b06:1; U08 b07:1;
        };
    };

    union Word
    {
        U16 all;
        struct
        {
            Byte lowByte;
            Byte highByte;
        };
        struct
        {
            U08 low;
            U08 high;
        };
        struct
        {
            U08 b00:1; U08 b01:1; U08 b02:1; U08 b03:1;
            U08 b04:1; U08 b05:1; U08 b06:1; U08 b07:1;
            U08 b08:1; U08 b09:1; U08 b10:1; U08 b11:1;
            U08 b12:1; U08 b13:1; U08 b14:1; U08 b15:1;
        };
    };

    union DWord
    {
        U32 all;
        struct
        {
            U16 low;
            U16 high;
        };
        struct
        {
            Word lowWord;
            Word highWord;
        };
        struct
        {
            U08 b00:1; U08 b01:1; U08 b02:1; U08 b03:1;
            U08 b04:1; U08 b05:1; U08 b06:1; U08 b07:1;
            U08 b08:1; U08 b09:1; U08 b10:1; U08 b11:1;
            U08 b12:1; U08 b13:1; U08 b14:1; U08 b15:1;
            U08 b16:1; U08 b17:1; U08 b18:1; U08 b19:1;
            U08 b20:1; U08 b21:1; U08 b22:1; U08 b23:1;
            U08 b24:1; U08 b25:1; U08 b26:1; U08 b27:1;
            U08 b28:1; U08 b29:1; U08 b30:1; U08 b31:1;
        };
    };
} // namespace nvm


#endif