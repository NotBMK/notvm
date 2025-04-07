#include <notvm.h>

using namespace nvm;

void Memory::reset()
{
    for (WORD page = 0; page < MAXN_PAGE; ++page)
    {
        for (WORD address = 0; address < PAGE_SIZE; ++address)
        {
            data[page][address] = 0;
        }
    }
}

BYTE Memory::byte(BYTE page, BYTE addr) const
{
    return data[page][addr];
}


BYTE& Memory::byte(BYTE page, BYTE addr)
{
    return data[page][addr];
}

WORD Memory::word(BYTE page, BYTE addr) const
{
    return *(((WORD*)(data[page])) + addr);
}

WORD& Memory::word(BYTE page, BYTE addr)
{
    return *(((WORD*)(data[page])) + addr);
}