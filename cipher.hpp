#pragma once
#include <string>
#include <vector>
#include "alph.hpp"

class Cipher
{
private:
    std::string _word;
    Alphabet &_alph;

public:
    Cipher(std::string, Alphabet &);
    std::vector<std::string> getCipheredVec();
    Cipher *setWord(std::string);
};
