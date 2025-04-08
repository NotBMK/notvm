#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using U08 = unsigned char;
    using U16 = unsigned short;
    using S08 = signed char;
    using S16 = signed short;

    enum Constant
    {
        PAGE_SIZE = 256, // size of per page
        MAXN_PAGE = 256, // amount of pages
        INST_MASK = 0xE3,
        MODE_MASK = 0x1C,
    };

    union Byte
    {
    public:

        Byte() noexcept;
        Byte(U08 data) noexcept;
        operator U08() const noexcept;
    
    public:

        U08 all;
        struct
        {
            U08 b00:1; U08 b01:1; U08 b02:1; U08 b03:1;
            U08 b04:1; U08 b05:1; U08 b06:1; U08 b07:1;
        };
    };

    union Word
    {
    public:

        Word() noexcept;
        Word(U08 low, U08 high) noexcept;
        Word(U16 data) noexcept;
        operator U16() const noexcept;

    public:

        U16 all;
        struct
        {
            Byte low;
            Byte highe;
        } byte;
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

    // unused
    enum AddressingMode : U08
    {
        IMM = 0b010,
        ZPG = 0b001,
        ZPX = 0b101,
        ABS = 0b011,
        ABX = 0b111,
        ABY = 0b110,
        INX = 0b000,
        INY = 0b100,
    };

    // unused
    union OpCode
    {
    public:

        OpCode();
        OpCode(U08 op);

    public:

        U08 all;
        struct
        {
            U08 low : 2;
            AddressingMode mode : 3;
            U08 high: 3;
        };
    };

    static_assert(sizeof(Byte) == 1, "sizeof(Byte) != 1");
    static_assert(sizeof(Word) == 2, "sizeof(Word) != 2");
    static_assert(sizeof(OpCode) == 1, "sizeof(OpCode) != 1");
} // namespace nvm


#endif