#include <notvm.h>

using namespace nvm;

void Memory::reset()
{
    for (int i = 0; i < MAX_MEMORY; i++)
    {
        data[i] = 0;
    }
}

BYTE Memory::operator[] (WORD address) const
{
    return data[address];
}

BYTE& Memory::operator[] (WORD address)
{
    return data[address];
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

BYTE CPU::fetchByte(WORD& cycles, Memory& memory)
{
    return --cycles, memory.data[PC++];
}

void CPU::execute(WORD cycles, Memory& memory)
{
    while (cycles > 0)
    {
        BYTE opcode = fetchByte(cycles, memory);
        // Decode and execute the opcode here
        // For example:
        switch (opcode)
        {
            case 0x00: // BRK - Force Break
                // Handle BRK instruction
                break;
            case 0x01: // ORA - Logical OR Accumulator with Memory
                // Handle ORA instruction
                break;
            // Add more opcodes as needed
            default:
                // Handle unknown opcode
                break;
        }
    }
}