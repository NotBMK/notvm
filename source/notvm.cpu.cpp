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

void CPU::view() const noexcept
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

void CPU::tick(WORD& cycles, BYTE ticks)
{
    cycles += ticks;
}

void CPU::statusLoad(BYTE CPU::* R)
{
    Z = (this->*R == 0);
    N = (this->*R & 0x80) > 0;
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