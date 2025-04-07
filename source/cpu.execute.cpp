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
        case LDA_IMM: loadRegister(&CPU::A, nextByte(cycles, memory)); break;
        case LDA_ZPG: loadRegister(&CPU::A, readByte(cycles, addressingZeroPage(cycles, memory), memory)); break;
        case LDA_ZPX: loadRegister(&CPU::A, readByte(cycles, addressingZeroPageX(cycles, memory), memory)); break;
        case LDA_ABS: loadRegister(&CPU::A, readByte(cycles, addressingAbsolute(cycles, memory), memory)); break;
        case LDA_ABX: loadRegister(&CPU::A, readByte(cycles, addressingAbsoluteX(cycles, memory), memory)); break;
        case LDA_ABY: loadRegister(&CPU::A, readByte(cycles, addressingAbsoluteY(cycles, memory), memory)); break;        
        case LDA_INX: loadRegister(&CPU::A, readByte(cycles, addressingIndirectX(cycles, memory), memory)); break;
        case LDA_INY: loadRegister(&CPU::A, readByte(cycles, addressingIndirectY(cycles, memory), memory)); break;

        case LDX_IMM: loadRegister(&CPU::X, nextByte(cycles, memory)); break;
        case LDX_ZPG: loadRegister(&CPU::X, readByte(cycles, addressingZeroPage(cycles, memory), memory)); break;
        case LDX_ZPY: loadRegister(&CPU::X, readByte(cycles, addressingZeroPageY(cycles, memory), memory)); break;
        case LDX_ABS: loadRegister(&CPU::X, readByte(cycles, addressingAbsolute(cycles, memory), memory)); break;
        case LDX_ABY: loadRegister(&CPU::X, readByte(cycles, addressingAbsoluteY(cycles, memory), memory)); break;

        case LDY_IMM: loadRegister(&CPU::Y, nextByte(cycles, memory)); break;
        case LDY_ZPG: loadRegister(&CPU::Y, readByte(cycles, addressingZeroPage(cycles, memory), memory)); break;
        case LDY_ZPX: loadRegister(&CPU::Y, readByte(cycles, addressingZeroPageX(cycles, memory), memory)); break;
        case LDY_ABS: loadRegister(&CPU::Y, readByte(cycles, addressingAbsolute(cycles, memory), memory)); break;
        case LDY_ABX: loadRegister(&CPU::Y, readByte(cycles, addressingAbsoluteX(cycles, memory), memory)); break;

        default:
            printf("unhandled instruction : '%02x'\n", inst);
            break;
        }
    }
    return cycles;
}