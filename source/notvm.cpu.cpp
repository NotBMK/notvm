#include <notvm.h>

using namespace nvm;

void CPU::reset()
{
    PC = 0x0000;
    SP = 0x00;
    A = X = Y = 0x00;
    Status = 0x00;
}

void CPU::resetWith(Memory& memory)
{
    reset();
    memory.reset();
}

BYTE CPU::nextByte(WORD& cycles, Memory& memory)
{
    BYTE inst = readByteFromMemory(cycles, PC_H, PC_L, memory);
    PC += 1;
    return inst;
}

BYTE CPU::readByteFromMemory(WORD& cycles, BYTE page, BYTE address, Memory& memory)
{
    BYTE data = memory.byte(page, address);
    tick(cycles, 1);
    return data;
}

WORD CPU::readWordFromMemory(WORD& cycles, BYTE page, BYTE address, Memory& memory)
{
    WORD data = memory.word(page, address);
    tick(cycles, 2);
    return data;
}