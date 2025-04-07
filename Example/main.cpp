#include <notvm.h>

using namespace std;

int main(int argc, char const *argv[])
{
    nvm::Memory memory;
    nvm::CPU cpu;

    cpu.resetWith(memory);

    memory[0x0000] = nvm::LSR_ABX;
    memory[0x0001] = 0x37;
    memory[0x0002] = 0x37;
    memory[0x0003] = nvm::NOP;
    memory[0x0037] = 0x37;
    memory[0x3737] = 0x80;

    nvm::U32 cycles = cpu.execute(9, memory);
    cpu.view();
    printf("3737 %02X\n", memory[0x3737]);
    printf("cycles cost: %d\n", cycles);

    return 0;
}
