#include <notvm.h>
#include <stdio.h>

using namespace nvm;

void CPU::showRegisters() const noexcept
{
    printf("PC: %04X SP: %04X A: %02X X: %02X Y: %02X\n", PC, SP, A, X, Y);
    printf("C: %d, Z: %d, I: %d, D: %d, B: %d, V: %d, N: %d\n", C, Z, I, D, B, V, N);
    printf("Status: %02X\n", Status);
}