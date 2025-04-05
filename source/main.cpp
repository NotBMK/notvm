#include <notvm.h>

int main(int argc, char const *argv[])
{
    nvm::Memory mem;
    nvm::CPU cpu;

    cpu.reset_with(mem);

    mem[0xFFFC] = nvm::LDA_IM;

    cpu.execute(10, mem); // Execute with 10 cycles

    return 0;
}
