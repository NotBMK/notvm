#ifndef INC__VM__H
#define INC__VM__H

#include <stdio.h>
#include <vmdef.h>
#include <opcodes.h>

namespace nvm
{
    class Memory
    {
    public:

        void reset();

        U08 byte(U08 page, U08 addr) const;
        
        U08& byte(U08 page, U08 addr);
        
        U16 word(U08 page, U08 addr) const;
        
        U16& word(U08 page, U08 addr);
    
    protected:

        U08 data[MAXN_PAGE][PAGE_SIZE];
    };

    class CPU
    {
    public:

        void reset();

        void resetWith(Memory& memory);

        U16 execute(U16 cyclesRequest, Memory& memory);

        void view() const noexcept;

    protected:

        void loadRegister(U08 CPU::* R, Byte value);

        void tick(U16& cycles, U08 ticks);

        Word addressingZeroPage(U16& cycles, Memory& memory);

        Word addressingZeroPageX(U16& cycles, Memory& memory);

        Word addressingZeroPageY(U16& cycles, Memory& memory);

        Word addressingAbsolute(U16& cycles, Memory& memory);

        Word addressingAbsoluteX(U16& cycles, Memory& memory);

        Word addressingAbsoluteY(U16& cycles, Memory& memory);

        Word addressingIndirectX(U16& cycles, Memory& memory);

        Word addressingIndirectY(U16& cycles, Memory& memory);

        Byte nextByte(U16& cycles, Memory& memory);

        Word nextWord(U16& cycles, Memory& memory);

        Byte readByteFromMemory(U16& cycles, U08 page, U08 address, Memory& memory);

        Word readWordFromMemory(U16& cycles, U08 page, U08 address, Memory& memory);

    protected:

        union
        {
            U16 PC; // program counter
            struct
            {
                U08 PC_L; // lowbit of program counter
                U08 PC_H; // highbit of program counter
            };
        };
        U08 SP;
        U08 A, X, Y;
        union
        {
            U08 Status; // status register
            struct
            {
                U08 C : 1; // carry
                U08 Z : 1; // zero
                U08 I : 1; // interrupt disable
                U08 D : 1; // decimal mode
                U08 B : 1; // break command
                U08 V : 1; // overflow
                U08 N : 1; // negative
                U08 _ : 1; // unused
            };
        };
    };
}; // ! namespace nvm

#endif