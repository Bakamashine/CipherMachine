#pragma once

#include <random>
#include <string>
#include <vector>

class Randomizer
{
private:
    int max = 100;
    int min = 0;
    std::random_device rd;
    std::mt19937 gen;
    const std::string &_alph;

public:
    Randomizer(std::string &);
    Randomizer &setMax(int max);
    Randomizer &setMin(int min);
    int getRandomNumber();
    int getRandomNumber(int max);
    char getRandomSymbol();
    std::string getAlphabet();
    void debugPrint();
    std::vector<int> generateKey(size_t size);
};
