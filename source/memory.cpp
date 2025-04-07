#include <notvm.h>

using namespace nvm;

void Memory::reset()
{
    for (U16 page = 0; page < MAXN_PAGE; ++page)
    {
        for (U16 address = 0; address < PAGE_SIZE; ++address)
        {
            data[page][address].all = 0;
        }
    }
}

Byte Memory::byte(Word address) const
{
    return data[address.high][address.low];
}

Byte& Memory::byte(Word address)
{
    return data[address.high][address.low];
}

Word Memory::word(Word address) const
{
    return *((Word*)(data[address.high] + address.low));
}

Word& Memory::word(Word address)
{
    return *((Word*)(data[address.high] + address.low));
}

U08 Memory::operator[] (U16 address) const
{
    return operator[] (address);
}

U08& Memory::operator[] (U16 address)
{
    Word addr;
    addr.all = address;
    return (*(U08*)&data[addr.high][addr.low]);
}