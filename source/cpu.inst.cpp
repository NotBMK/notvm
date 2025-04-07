#include <notvm.h>

using namespace nvm;

void CPU::loadRegister(Byte CPU::* R, Byte value)
{
    this->*R = value;
    Z = ((this->*R).all == 0);
    N = ((this->*R).b07);
}

void CPU::logicalShiftRight(U16& cycles, Byte& target)
{
    C = target.b00;
    target.all >>= 1;
    N = target.b07;
    Z = (target.all == 0);
    tick(cycles, 1);
}

void CPU::logicalShiftRight(U16& cycles, Word address, Memory& memory)
{
    return logicalShiftRight(cycles, memory.byte(address)), tick(cycles, 2);
}

void CPU::noOperation(U16& cycles) const
{
    return tick(cycles, 1);
}

void CPU::push(U16& cycles, Byte data, Memory& memory)
{
    return memory.byte(Word(SP.all--, 1)) = data, tick(cycles, 2);
}

Byte CPU::pull(U16& cycles, Memory& memory)
{
    return tick(cycles, 3), memory.byte(Word(++SP.all, 1));
}
