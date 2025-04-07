#include <notvm.h>

using namespace nvm;

U32 CPU::execute(WORD cyclesRequest, Memory& memory)
{
    WORD cycles = 0;
    while (cycles < cyclesRequest)
    {
        BYTE inst = nextByte(cycles, memory);
        switch (inst)
        {
        case LDA_IMM:
        {
            BYTE data = nextByte(cycles, memory);
            A = data;
            statusLoad(&CPU::A);
        } break;

        case LDA_ZPG:
        {
            BYTE addr = nextByte(cycles, memory);
            A = memory.byte(0, addr); tick(cycles, 1);
            statusLoad(&CPU::A);
        } break;

        case LDA_ZPX:
        {
            BYTE addr = nextByte(cycles, memory);
            addr += X;
            A = readByteFromMemory(cycles, 0, addr, memory);
        } break;

        case LDA_ABS:
        {

        } break;

        case LDA_ABX:
        {

        } break;

        case LDA_ABY:
        {

        } break;

        case LDA_INX:
        {

        } break;

        case LDA_INY:
        {

        } break;

        
        default:
            printf("unhandled instruction : '%02x'\n", inst);
            break;
        }
    }
    return cycles;
}