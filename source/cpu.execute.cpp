#include <notvm.h>

using namespace nvm;

U16 CPU::execute(U16 cyclesRequest, Memory& memory)
{
    U16 cycles = 0;
    while (cycles < cyclesRequest)
    {
        Byte inst = nextByte(cycles, memory);
        switch (inst.all)
        {
        case LDA_IMM:
        {
            loadRegister(&CPU::A, nextByte(cycles, memory));
        } break;

        case LDX_IMM:
        {
            loadRegister(&CPU::X, nextByte(cycles, memory));
        } break;

        case LDA_ZPG:
        {
            Word addr = addressingZeroPage(cycles, memory);
            loadRegister(&CPU::A, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDX_ZPG:
        {
            Word addr = addressingZeroPage(cycles, memory);
            loadRegister(&CPU::X, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDA_ZPX:
        {
            Word addr = addressingZeroPageX(cycles, memory);
            loadRegister(&CPU::A, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDA_ABS:
        {
            Word addr = addressingAbsolute(cycles, memory);
            loadRegister(&CPU::A, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDA_ABX:
        {
            Word addr = addressingAbsoluteX(cycles, memory);
            loadRegister(&CPU::A, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDA_ABY:
        {
            Word addr = addressingAbsoluteY(cycles, memory);
            loadRegister(&CPU::A, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDA_INX:
        {
            Word addr = addressingIndirectX(cycles, memory);
            loadRegister(&CPU::A, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDA_INY:
        {
            Word addr = addressingIndirectY(cycles, memory);
            loadRegister(&CPU::A, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDX_ZPY:
        {
            Word addr = addressingZeroPageY(cycles, memory);
            loadRegister(&CPU::X, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDX_ABS:
        {
            Word addr = addressingAbsolute(cycles, memory);
            loadRegister(&CPU::X, readByteFromMemory(cycles, addr, memory));
        } break;

        case LDX_ABY:
        {

        } break;

        default:
            printf("unhandled instruction : '%02x'\n", inst);
            break;
        }
    }
    return cycles;
}