#include <notvm.h>

int main(int argc, char const *argv[])
{
    nvm::Memory mem;
    nvm::CPU cpu;

    cpu.reset_with(mem);

    mem[0xFFFC] = nvm::INST_JSR;
    mem[0xFFFD] = 0x42;
    mem[0xFFFE] = 0x42;
    
    cpu.X = 0x80;
    mem[0x4242] = nvm::INST_LDA_ABSX;
    mem[0x4243] = 0x00;
    mem[0x4244] = 0x84;
        mem[0x8480] = 0x42;

    mem[0x4245] = nvm::INST_LDX_IM;
    mem[0x4246] = 0x37;

    cpu.execute(12, mem); // Execute with 9 cycles
    cpu.showRegisters(); // Show registers after execution

    return 0;
}
