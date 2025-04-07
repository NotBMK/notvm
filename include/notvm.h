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

        U32 execute(WORD cyclesRequest, Memory& memory)
        {
            WORD cycles = 0;
            while (cycles < cyclesRequest)
            {
                BYTE inst = nextByte(cycles, memory);
                switch (inst)
                {
                case LDA_IMM:
                {
                    BYTE data = nextByte(cycles, memory);
                    A = data;
                    statusLoad<&CPU::A>();
                } break;

                case LDA_ZPG:
                {
                    BYTE addr = nextByte(cycles, memory);
                    A = memory.byte(0, addr); tick(cycles, 1);
                    statusLoad<&CPU::A>();
                } break;

                case LDA_ZPX:
                {
                    BYTE addr = nextByte(cycles, memory);
                    addr += X;
                    A = readByteFromMemory(cycles, 0, addr, memory);
                } break;

                case LDA_ABS:
                {

                } break;

                case LDA_ABX:
                {

                } break;

                case LDA_ABY:
                {

                } break;

                case LDA_INX:
                {

                } break;

                case LDA_INY:
                {

                } break;

                
                default:
                    printf("unhandled instruction : '%02x'\n", inst);
                    break;
                }
            }
            return cycles;
        }

        void view() const noexcept
        {
            printf(
                "A: %02X, X: %02X, Y: %02X\n"
                "PC: %04X, SP: %04X\n"
                "Status:\n"
                "\t%1d %1d %1d %1d %1d %1d %1d\n"
                "\tN V B D I Z C\n\n",
                A, X, Y,
                PC, SP,
                N, V, B, D, I, Z, C
                );
        }

    protected:

        constexpr static inline
        void tick(WORD& cycles, BYTE ticks)
        { cycles += ticks; }

        template <BYTE CPU::* R>
        constexpr inline
        void statusLoad()
        {
            Z = (this->*R == 0);
            N = (this->*R & 0x80) > 0;
        }

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