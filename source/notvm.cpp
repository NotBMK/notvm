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

BYTE CPU::readByte(WORD& cycles, BYTE address, Memory& memory) const
{
    BYTE data = memory[address];
    --cycles;
    return data;
}


BYTE CPU::fetchByte(WORD& cycles, Memory& memory)
{
    BYTE data = memory[PC];
    ++PC; --cycles;
    return data;
}

BYTE CPU::fetchWord(WORD& cycles, Memory& memory)
{
    WORD data = memory[PC];
    ++PC;
    data |= (memory[PC] << 8);
    cycles -= 2;
    return data;
}

void CPU::StatusLDA()
{
    Z = (A == 0);
    N = (A & 0x80) > 0;
}

void CPU::execute(WORD cycles, Memory& memory)
{
    while (cycles > 0)
    {
        BYTE inst = fetchByte(cycles, memory);
        // Decode and execute the inst here
        // For example:
        switch (inst)
        {
        case INST_LDA_IM:
        {
            A = fetchByte(cycles, memory);
            StatusLDA();
        } break;

        case INST_LDA_ZP:
        {
            BYTE address = fetchByte(cycles, memory);
            A = readByte(cycles, address, memory);
            StatusLDA();
        } break;

        case INST_LDA_ZPX:
        {
            BYTE address = fetchByte(cycles, memory);
            address += X; --cycles;
            A = readByte(cycles, address, memory);
            StatusLDA();
        } break;

        case INST_JSR:
        {
            WORD subAddr = fetchWord(cycles, memory);
            memory.writeWord(PC-1, SP, cycles);
            ++SP;
            PC = subAddr; --cycles;
        } break;

        default:
        {
            printf("Instruction '%d' not handled.\n", inst);
        } break;
        }
    }
}