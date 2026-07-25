#include "numbers.hpp"
#include "structurs.hpp"
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

Numbers::Numbers()
{
    this->numbers = new AlphHex[alph.size()];
    for (int i = 0; i < alph.size(); i++)
    {
        this->numbers[i].symbol = alph[i];
        this->numbers[i].value = 10 + i;
    }
}

Numbers::~Numbers()
{
    delete[] this->numbers;
}

long long Numbers::convert_to_standart(std::string val)
{
    long long result = 0;
    long long power = 0;

    for (int i = val.size() - 1; i >= 0; i--)
    {
        bool found = false;
        for (int j = 0; j < alph.size(); j++)
        {
            if (val[i] == numbers[j].symbol)
            {
                result += numbers[j].value * pow(16, power);
                power++;
                found = true;
                break;
            }
        }
        if (!found)
        {
            result += (val[i] - '0') * pow(16, power);
            power++;
        }
    }

    return result;
}

long long Numbers::multiplication_hex(std::string v1, std::string v2)
{
    return this->convert_to_standart(v1) * this->convert_to_standart(v2);
}
