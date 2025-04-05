#include <notvm.h>

using namespace nvm;

void Memory::reset()
{
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        data[i] = 0;
    }
}

void CPU::reset()
{
    PC = 0xFFFC;
    SP = 0x0100;
    A = X = Y = 0;

    C = Z = I = D = B = V = N = _ = 0; // Clear all flags  
}

void CPU::reset_with(Memory &mem)
{
    reset();
    mem.reset();
}

