#ifndef INC__NOTVM__H
#define INC__NOTVM__H

#include <vmdef.h>

namespace nvm
{
    struct Memory
    {
        enum
        {
            MAX_MEMORY = 0x10000, // 64KB of memory
            MAX_PAGES = 0x100, // 256 pages
            PAGE_SIZE = 0x100 // 256 bytes per page
        };

        BYTE data[MAX_MEMORY]; // 64KB of memory

        void reset();

        BYTE operator[] (WORD address) const;

        BYTE& operator[] (WORD address);
    };

    // 6502 CPU registers and flags
    struct CPU
    {
        void reset();

        void reset_with(Memory &mem);

        BYTE readByte(WORD& cycles, BYTE address, Memory& memory) const;

        // Fetch the next byte from memory and increment the program counter
        // Decrement cycles for each fetch
        BYTE fetchByte(WORD& cycles, Memory& memory);

        void execute(WORD cycles, Memory& memory);

    protected:
        
        WORD PC; // Program Counter
        WORD SP; // Stack Pointer

        BYTE A, X, Y; // registers

        struct
        {
            BYTE C : 1; // Carry
            BYTE Z : 1; // Zero
            BYTE I : 1; // Interrupt Disable
            BYTE D : 1; // Decimal Mode
            BYTE B : 1; // Break Command
            BYTE V : 1; // Overflow
            BYTE N : 1; // Negative
            BYTE _ : 1; // unused
        };
    };
} // namespace nvm


#endif