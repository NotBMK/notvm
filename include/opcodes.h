#ifndef INC__VM_OP_CODES__H
#define INC__VM_OP_CODES__H

#include <vmdef.h>

namespace nvm
{
    enum Instruction
    {
        NOP = 0xEA, // No Operation

        ADC_IMM = 0x69, // Add with Carry, Addressing Mode: Immediate
        ADC_ZPG = 0x65, // Add with Carry, Addressing Mode: Zero Page
        ADC_ZPX = 0x75, // Add with Carry, Addressing Mode: Zero Page, X
        ADC_ABS = 0x6D, // Add with Carry, Addressing Mode: Absolute
        ADC_ABX = 0x7D, // Add with Carry, Addressing Mode: Absolute, X
        ADC_ABY = 0x79, // Add with Carry, Addressing Mode: Absolute, Y
        ADC_INX = 0x61, // Add with Carry, Addressing Mode: (Indirect, X)
        ADC_INY = 0x71, // Add with Carry, Addressing Mode: (Indirect), Y

        AND_IMM = 0x29, // Logical AND, Addressing Mode: Immediate
        AND_ZPG = 0x25, // Logical AND, Addressing Mode: Zero Page
        AND_ZPX = 0x35, // Logical AND, Addressing Mode: Zero Page, X
        AND_ABS = 0x2D, // Logical AND, Addressing Mode: Absolute
        AND_ABX = 0x3D, // Logical AND, Addressing Mode: Absolute, X
        AND_ABY = 0x39, // Logical AND, Addressing Mode: Absolute, Y
        AND_INX = 0x21, // Logical AND, Addressing Mode: (Indirect, X)
        AND_INY = 0x31, // Logical AND, Addressing Mode: (Indirect), Y

        LDA_IMM = 0xA9, // Load Register A, Addressing Mode: Immediate
        LDA_ZPG = 0xA5, // Load Register A, Addressing Mode: Zero Page
        LDA_ZPX = 0xB5, // Load Register A, Addressing Mode: Zero Page, X
        LDA_ABS = 0xAD, // Load Register A, Addressing Mode: Absolute
        LDA_ABX = 0xBD, // Load Register A, Addressing Mode: Absolute, X
        LDA_ABY = 0xB9, // Load Register A, Addressing Mode: Absolute, Y
        LDA_INX = 0xA1, // Load Register A, Addressing Mode: (Indirect, X)
        LDA_INY = 0xB1, // Load Register A, Addressing Mode: (Indirect), Y

        LDX_IMM = 0xA2, // Load Register X, Addressing Mode: Immediate
        LDX_ZPG = 0xA6, // Load Register X, Addressing Mode: Zero Page
        LDX_ZPY = 0xB6, // Load Register X, Addressing Mode: Zero Page, Y
        LDX_ABS = 0xAE, // Load Register X, Addressing Mode: Absolute
        LDX_ABY = 0xBE, // Load Register X, Addressing Mode: Absolute, Y

        LDY_IMM = 0xA0, // Load Register Y, Addressing Mode: Immediate
        LDY_ZPG = 0xA4, // Load Register Y, Addressing Mode: Zero Page
        LDY_ZPX = 0xB4, // Load Register Y, Addressing Mode: Zero Page, X
        LDY_ABS = 0xAC, // Load Register Y, Addressing Mode: Absolute
        LDY_ABX = 0xBC, // Load Register Y, Addressing Mode: Absolute, X

        LSR_ACC = 0x4A, // Logical Shift Right, Addressing Mode: Acculator
        LSR_ZPG = 0x46, // Logical Shift Right, Addressing Mode: Zero Page
        LSR_ZPX = 0x56, // Logical Shift Right, Addressing Mode: Zero Page, X
        LSR_ABS = 0x4E, // Logical Shift Right, Addressing Mode: Absolute
        LSR_ABX = 0x5E, // Logical Shift Right, Addressing Mode: Absolute, X

        PHA = 0x48, // Push Accumulator
        PHP = 0x08, // Push Processor Status
        PLA = 0x68, // Pull Accumulator
        PLP = 0x28, // Pull Processor Status
        
    };
} // namespace nvm

#endif