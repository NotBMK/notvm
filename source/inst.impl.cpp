#include <stdio.h>

#include <notvm.h>

using namespace nvm;

WORD CPU::execute(WORD cyclesRequest, Memory& memory)
{
    WORD cycles = 0;
    while (cycles < cyclesRequest)
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
            address += X; ++cycles;
            A = readByte(cycles, address, memory);
            StatusLDA();
        } break;

        case INST_LDA_ABS:
        {
            
        } break;

        case INST_JSR:
        {
            WORD subAddr = fetchWord(cycles, memory);
            memory.writeWord(PC-1, SP, cycles);
            SP += 2;
            PC = subAddr; ++cycles;
        } break;

        default:
        {
            printf("Instruction '%d' not handled.\n", inst);
        } break;
        }
    }
    return -1;
}