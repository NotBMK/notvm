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

        // read 1 byte
        BYTE operator[] (WORD address) const;

        // write 1 byte
        BYTE& operator[] (WORD address);

        // write 2 bytes
        void writeWord(WORD value, WORD address, WORD& cycles);
    };

    // 6502 CPU registers and flags
    struct CPU
    {
        void reset();

        void reset_with(Memory &mem);

        BYTE readByte(WORD& cycles, BYTE address, Memory& memory) const;

        BYTE fetchByte(WORD& cycles, Memory& memory);
        BYTE fetchWord(WORD& cycles, Memory& memory);

        WORD execute(WORD cycles, Memory& memory);

    private:

        void StatusLDA();

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