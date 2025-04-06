#include <stdio.h>

#include <notvm.h>

using namespace nvm;

WORD CPU::execute(WORD cyclesRequest, Memory& memory)
{
    WORD cycles = 0;
    while (cycles < cyclesRequest)
    {
        BYTE inst = fetchByte(cycles, memory);
        switch (inst)
        {
        case INST_LDA_IM:
        {
            A = fetchByte(cycles, memory);
            StatusLoadRegister(A);
        } break;

        case INST_LDX_IM:
        {
            X = fetchByte(cycles, memory);
            StatusLoadRegister(X);
        } break;

        case INST_LDY_IM:
        {
            Y = fetchByte(cycles, memory);
            StatusLoadRegister(Y);
        } break;

        case INST_LDA_ZP:
        {
            BYTE address = fetchByte(cycles, memory);
            A = readByte(cycles, address, memory);
            StatusLoadRegister(A);
        } break;

        case INST_LDA_ZPX:
        {
            BYTE address = fetchByte(cycles, memory);
            address += X; ++cycles;
            A = readByte(cycles, address, memory);
            StatusLoadRegister(A);
        } break;

        case INST_LDA_ABS:
        {
            WORD absAddr = fetchWord(cycles, memory);
            A = readByte(cycles, absAddr, memory);
            StatusLoadRegister(A);
        } break;

        case INST_LDA_ABSX:
        {
            WORD absAddr = fetchWord(cycles, memory);
            WORD newAddr  = absAddr+= X;
            A = readByte(cycles, newAddr, memory);
            if ((absAddr & 0xFF00) != (newAddr & 0xFF00)) ++cycles;
            StatusLoadRegister(A);
        } break;

        case INST_LDA_ABSY:
        {
            WORD absAddr = fetchWord(cycles, memory);
            WORD newAddr  = absAddr+= Y;
            A = readByte(cycles, newAddr, memory);
            if ((absAddr & 0xFF00) != (newAddr & 0xFF00)) ++cycles;
            StatusLoadRegister(A);
        } break;

        case INST_LDA_INDX:
        {
            BYTE address = fetchByte(cycles, memory);
            WORD midAddr = address + X;
            WORD finAddr = readWord(cycles, midAddr, memory);
            A = readByte(cycles, finAddr, memory);
            StatusLoadRegister(A);
        } break;

        case INST_LDA_INDY:
        {
            BYTE address = fetchByte(cycles, memory);
            WORD midAddr = readWord(cycles, address, memory);
            WORD finAddr = address + Y;
            A = readByte(cycles, finAddr, memory);
            if ((midAddr & 0xFF00) != (finAddr & 0xFF00)) ++cycles;
            StatusLoadRegister(A);
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
    return cycles;
}