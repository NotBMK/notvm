#include <notvm.h>

using namespace nvm;

Word CPU::addressingZeroPage(U16& cycles, Memory& memory)
{
    Word addr;
    addr.lowByte = nextByte(cycles, memory);
    addr.high = 0;
    return addr;
}

Word CPU::addressingZeroPageX(U16& cycles, Memory& memory)
{
    Word addr = addressingZeroPage(cycles, memory);
    addr.low += X;
    return addr;
}

Word CPU::addressingZeroPageY(U16& cycles, Memory& memory)
{
    Word addr = addressingZeroPage(cycles, memory);
    addr.low += Y;
    return addr;
}

Word CPU::addressingAbsolute(U16& cycles, Memory& memory)
{
    return nextWord(cycles, memory);
}

Word CPU::addressingAbsoluteX(U16& cycles, Memory& memory)
{
    Word addr = addressingAbsolute(cycles, memory);
    U08 page = addr.high;
    addr.all += X;
    if (page != addr.high) tick(cycles, 1);
    return addr;
}

Word CPU::addressingAbsoluteY(U16& cycles, Memory& memory)
{
    Word addr = addressingAbsolute(cycles, memory);
    U08 page = addr.high;
    addr.all += Y;
    if (page != addr.high) tick(cycles, 1);
    return addr;
}

Word CPU::addressingIndirectX(U16& cycles, Memory& memory)
{
    Word addr;
    addr.low = nextByte(cycles, memory).all + X;
    tick(cycles, 1);
    addr.high = 0;
    addr = readWordFromMemory(cycles, addr.high, addr.low, memory);
    return addr;
}

Word CPU::addressingIndirectY(U16& cycles, Memory& memory)
{
    Word addr;
    addr.lowByte = nextByte(cycles, memory);
    addr.high = 0;
    addr = readWordFromMemory(cycles, addr.high, addr.low, memory);
    U08 page = addr.high;
    addr.all += Y;
    if (page != addr.high)
        tick(cycles, 1);
    return addr;
}