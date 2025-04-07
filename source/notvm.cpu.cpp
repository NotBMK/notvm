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

void CPU::tick(U16& cycles, U08 ticks)
{
    cycles += ticks;
}

void CPU::loadRegister(U08 CPU::* R, Byte value)
{
    this->*R = value.all;
    Z = (value.all == 0);
    N = value.b07;
}

Byte CPU::nextByte(U16& cycles, Memory& memory)
{
    Byte data = readByteFromMemory(cycles, PC_H, PC_L, memory);
    PC += 1;
    return data;
}

Word CPU::nextWord(U16& cycles, Memory& memory)
{
    Word data = readWordFromMemory(cycles, PC_H, PC_L, memory);
    PC += 2;
    return data;
}

Byte CPU::readByteFromMemory(U16& cycles, U08 page, U08 address, Memory& memory)
{
    Byte data;
    data.all = memory.byte(page, address);
    tick(cycles, 1);
    printf("readByteFromMemory: %02X %02X %02X\n", page, address, data.all);
    return data;
}

Word CPU::readWordFromMemory(U16& cycles, U08 page, U08 address, Memory& memory)
{
    Word data;
    data.all = memory.word(page, address);
    tick(cycles, 2);
    printf("readWordFromMemory: %02X %02X %04X\n", page, address, data.all);
    return data;
}