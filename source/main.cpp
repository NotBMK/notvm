#include <notvm.h>

int main(int argc, char const *argv[])
{
    nvm::Memory mem;
    nvm::CPU cpu;

    cpu.reset_with(mem);

    mem[0xFFFC] = nvm::INST_JSR;
    mem[0xFFFD] = 0x42;
    mem[0xFFFE] = 0x42;
    mem[0x4242] = nvm::INST_LDA_IM;
    mem[0x4243] = 0x84;

    cpu.execute(9, mem); // Execute with 9 cycles

    return 0;
}
