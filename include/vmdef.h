#ifndef INC__VM_DEF__H
#define INC__VM_DEF__H

namespace nvm
{
    using BYTE = unsigned char;
    using WORD = unsigned short;
    using DWORD = unsigned int;

    struct Register
    {
        union
        {
            struct
            {
                BYTE L;
                BYTE H;
            };
            WORD X;
        };
    };

    enum OpCode
    {
        SET, PUSH, POP,

        ADD, SUB, MUL, DIV, INC, DEC,

        AND, OR, XOR, NOT,

        CMP,

        JMP, JZ, JNZ,

        OP_AMOUNT,
    };

    enum OpCodeMask
    {
        NONE = 0b0000'0000,
        CODE = 0b0001'1111,
        ARG_REG  = 0b0010'0000,
        ARG_IMM  = 0b0100'0000,
        ARG_MEM  = 0b1000'0000,
    };

    enum RegisterEnum
    {
        AX, BX, CX, DX,
        SP, BP, IP,
        CS, DS, ES, FS, GS, SS,
        REG_AMOUNT,
    };
} // namespace nvm


#endif