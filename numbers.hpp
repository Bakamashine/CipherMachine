#pragma once

#include "structurs.hpp"
#include <string>

class Numbers
{
private:
    long long conToStandard(std::string);
    struct AlphabetHex *_numbers;
    const std::string _alph = "ABCDEF";

public:
    long long multiplicationHex(std::string, std::string);
    Numbers();
    ~Numbers();
};
