#include <notvm.h>

using namespace nvm;

void Memory::reset()
{
    for (U16 page = 0; page < MAXN_PAGE; ++page)
    {
        for (U16 address = 0; address < PAGE_SIZE; ++address)
        {
            data[page][address] = 0;
        }
    }
}

U08 Memory::byte(U08 page, U08 addr) const
{
    return data[page][addr];
}


U08& Memory::byte(U08 page, U08 addr)
{
    return data[page][addr];
}

U16 Memory::word(U08 page, U08 addr) const
{
    return *((U16*)(data[page] + addr));
}

U16& Memory::word(U08 page, U08 addr)
{
    return *((U16*)(data[page] + addr));
}