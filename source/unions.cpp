#include <notvm.h>

using namespace nvm;

Byte::Byte() noexcept
{ }

Byte::Byte(U08 data) noexcept
: all(data)
{ }

Byte::operator U08() const noexcept
{
    return all;
}

Word::Word() noexcept
{ }

Word::Word(U08 low, U08 high) noexcept
: low(low), high(high)
{ }

Word::Word(U16 data) noexcept
: all(data)
{ }

Word::operator U16() const noexcept
{
    return all;
}
