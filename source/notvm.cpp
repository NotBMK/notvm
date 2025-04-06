#include <notvm.h>

#include <stdio.h>

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

void Memory::writeWord(WORD value, WORD address, WORD& cycles)
{
    data[address] = value & 0xFF;
    data[address+1] = (value >> 8);
    cycles += 2;
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

BYTE CPU::readByte(WORD& cycles, WORD address, Memory& memory) const
{
    BYTE data = memory[address];
    printf("Read byte: %02X from address: %04X\n", data, address);
    ++cycles;
    return data;
}

WORD CPU::readWord(WORD& cycles, WORD address, Memory& memory) const
{
    BYTE low = readByte(cycles, address, memory);
    BYTE high = readByte(cycles, address + 1, memory);
    WORD data = low | (high << 8);
    printf("- Read word: %04X from address: %04X\n", data, address);
    return data;
}

BYTE CPU::fetchByte(WORD& cycles, Memory& memory)
{
    BYTE data = readByte(cycles, PC, memory);
    ++PC;
    return data;
}

WORD CPU::fetchWord(WORD& cycles, Memory& memory)
{
    WORD data = readWord(cycles, PC, memory);
    PC += 2;
    return data;
}

void CPU::StatusLoadRegister(BYTE R)
{
    Z = (R == 0);
    N = (R & 0x80) > 0;
}
