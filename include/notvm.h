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

        Byte byte(Word address) const;
        
        Byte& byte(Word address);
        
        Word word(Word address) const;
        
        Word& word(Word address);

        U08 operator[] (U16 address) const;
        
        U08& operator[] (U16 address);
    
    protected:

        Byte data[MAXN_PAGE][PAGE_SIZE];
    };

    class CPU
    {
    public:

        void reset();

        void resetWith(Memory& memory);

        U16 execute(U16 cyclesRequest, Memory& memory);

        void view() const noexcept;

    protected: // do instruction

        void loadRegister(Byte CPU::* R, Byte value);

        void logicalShiftRight(U16& cycles, Byte& target);
        
        void logicalShiftRight(U16& cycles, Word address, Memory& memory);

        void noOperation(U16& cycles) const;

    protected: // addressing mode
    
        Word addressingZeroPage(U16& cycles, Memory& memory);
        
        Word addressingZeroPageX(U16& cycles, Memory& memory);
        
        Word addressingZeroPageY(U16& cycles, Memory& memory);
        
        Word addressingAbsolute(U16& cycles, Memory& memory);
        
        Word addressingAbsoluteX(U16& cycles, Memory& memory);
        
        Word addressingAbsoluteY(U16& cycles, Memory& memory);
        
        Word addressingIndirectX(U16& cycles, Memory& memory);
        
        Word addressingIndirectY(U16& cycles, Memory& memory);
    
    protected: // helper funciton
    
        void tick(U16& cycles, U08 ticks) const noexcept;
        
        Byte nextByte(U16& cycles, Memory& memory);

        Word nextWord(U16& cycles, Memory& memory);

        Byte readByte(U16& cycles, Word address, Memory& memory) const noexcept;

        Word readWord(U16& cycles, Word address, Memory& memory) const noexcept;

    protected:

        Word PC;
        Byte SP;
        Byte A, X, Y;
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
                // U08 _ : 1; // unused
            };
        };
    };
}; // ! namespace nvm

#endif