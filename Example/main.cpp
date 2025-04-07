#include <notvm.h>

using namespace std;

int main(int argc, char const *argv[])
{
    nvm::Memory memory;
    nvm::CPU cpu;

    cpu.resetWith(memory);

    memory[0x0000] = nvm::LDA_ABS;
    memory[0x0001] = 0x37;
    memory[0x0002] = 0x37;
    memory[0x0003] = nvm::PHA;
    memory[0x0004] = nvm::PLP;
    memory[0x0037] = 0x08;
    memory[0x3737] = 0x8F;

    nvm::U16 cycles = cpu.execute(8, memory);
    cpu.view();
    printf("cycles cost: %d\n", cycles);

    return 0;
}
