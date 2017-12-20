#include "test.h"

Test::Test()
{
    number = 0;
}

void Test::SetNumber(int num)
{
    number = num;
}

int Test::GetNumber()
{
    return number;
}
