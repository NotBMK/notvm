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
    tick(cycles, 1);
    C = target.b00;
    target.all >>= 1;
    N = target.b07;
    Z = (target.all == 0);
}

void CPU::logicalShiftRight(U16& cycles, Word address, Memory& memory)
{
    logicalShiftRight(cycles, memory.byte(address));
    tick(cycles, 2);
}

void CPU::noOperation(U16& cycles) const
{
    tick(cycles, 1);
}
