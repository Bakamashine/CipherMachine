#pragma once

#include "structurs.hpp"
#include <string>

class Numbers
{
private:
    long long convert_to_standart(std::string);
    struct AlphHex* numbers;
    const std::string alph = "ABCDEF";
public:
    long long multiplication_hex(std::string,std::string);
    Numbers();
    ~Numbers();
};
