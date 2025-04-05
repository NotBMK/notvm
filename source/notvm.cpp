#include <notvm.h>

using namespace nvm;

void VirtualMachine::execute()
{
    BYTE inst = nextInst();
    switch (inst & CODE)
    {
    case SET:
    {

    } break;
    case PUSH:
    {
        memory[cpu[SP].X--] = nextInst();
        memory[cpu[SP].X--] = nextInst();
    } break;
    case POP:
    {

    } break;
    };
}

BYTE VirtualMachine::nextInst()
{
    return memory[cpu[CS].X + (cpu[IP].X++)];
}