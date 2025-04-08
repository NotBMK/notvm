#include <notvm.h>

using namespace nvm;

void CPU::reset()
{
    PC.all = 0x0000;
    SP.all = 0xFF;
    A.all = X.all = Y.all = 0x00;
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
        "Status: N V B D I Z C\n"
        "        %1d %1d %1d %1d %1d %1d %1d\n",
        A.all, X.all, Y.all,
        PC.all, SP.all,
        N, V, B, D, I, Z, C
        );
}

void CPU::tick(U16& cycles, U08 ticks) noexcept
{
    cycles += ticks;
}

Byte CPU::nextByte(U16& cycles, Memory& memory)
{
    Byte data = readByte(cycles, PC, memory);
    PC.all += 1;
    return data;
}

Word CPU::nextWord(U16& cycles, Memory& memory)
{
    Word data = readWord(cycles, PC, memory);
    PC.all += 2;
    return data;
}

Byte CPU::readByte(U16& cycles, Word address, Memory& memory) const noexcept
{
    Byte data = memory.byte(address);
    tick(cycles, 1);
    printf("readByteFromMemory: %02X %02X %02X\n", address.high, address.low, data.all);
    return data;
}

Word CPU::readWord(U16& cycles, Word address, Memory& memory) const noexcept
{
    Word data = memory.word(address);
    tick(cycles, 2);
    printf("readWordFromMemory: %02X %02X %04X\n", address.high, address.low, data.all);
    return data;
}