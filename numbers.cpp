#include "numbers.hpp"
#include "structurs.hpp"
#include <cstdlib>
#include <cmath>
#include <vector>
#include <string>

Numbers::Numbers()
{
    this->_numbers = new AlphabetHex[_alph.size()];
    for (int i = 0; i < _alph.size(); i++)
    {
        this->_numbers[i].symbol = _alph[i];
        this->_numbers[i].value = 10 + i;
    }
}

Numbers::~Numbers()
{
    delete[] this->_numbers;
}

long long Numbers::conToStandard(std::string val)
{
    long long result = 0;
    long long power = 0;

    for (int i = val.size() - 1; i >= 0; i--)
    {
        bool found = false;
        for (int j = 0; j < _alph.size(); j++)
        {
            if (val[i] == _numbers[j].symbol)
            {
                result += _numbers[j].value * pow(16, power);
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

long long Numbers::multiplicationHex(std::string v1, std::string v2)
{
    return this->conToStandard(v1) * this->conToStandard(v2);
}
