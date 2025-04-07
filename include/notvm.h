#ifndef INC__VM__H
#define INC__VM__H

#include <stdio.h>
#include <vmdef.h>

namespace nvm
{
    class Memory
    {
    public:

        void reset();

        BYTE byte(BYTE page, BYTE addr) const;
        
        BYTE& byte(BYTE page, BYTE addr);
        
        WORD word(BYTE page, BYTE addr) const;
        
        WORD& word(BYTE page, BYTE addr);
    
    protected:

        BYTE data[MAXN_PAGE][PAGE_SIZE];
    };

    class CPU
    {
    public:

        void reset();

        void resetWith(Memory& memory);

        U32 execute(WORD cyclesRequest, Memory& memory);

        void view() const noexcept;

    protected:

        void tick(WORD& cycles, BYTE ticks);

        void statusLoad(BYTE CPU::* R);

        BYTE nextByte(WORD& cycles, Memory& memory);

        BYTE readByteFromMemory(WORD& cycles, BYTE page, BYTE address, Memory& memory);

        WORD readWordFromMemory(WORD& cycles, BYTE page, BYTE address, Memory& memory);

    protected:

        union
        {
            WORD PC; // program counter
            struct
            {
                BYTE PC_L; // lowbit of program counter
                BYTE PC_H; // highbit of program counter
            };
        };
        BYTE SP;
        BYTE A, X, Y;
        union
        {
            BYTE Status; // status register
            struct
            {
                BYTE C : 1; // carry
                BYTE Z : 1; // zero
                BYTE I : 1; // interrupt disable
                BYTE D : 1; // decimal mode
                BYTE B : 1; // break command
                BYTE V : 1; // overflow
                BYTE N : 1; // negative
                BYTE _ : 1; // unused
            };
        };
    };
}; // ! namespace nvm

#endif