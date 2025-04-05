#ifndef INC__NOTVM__H
#define INC__NOTVM__H

#include <vmdef.h>

namespace nvm
{
    struct CPU
    {
        Register regs[REG_AMOUNT];

        constexpr
        Register& operator[](RegisterEnum reg)
        {
            return regs[reg];
        }
    };

    struct VirtualMachine
    {

        void execute();

        BYTE nextInst();

        CPU cpu;
        BYTE memory[65536];
    };
} // namespace nvm


#endif