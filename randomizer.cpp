#include "randomizer.h"
#include <random>
#include <iostream>

Randomizer::Randomizer(std::string &_alph) : _alph(_alph), gen(rd())
{
}

Randomizer &Randomizer::setMax(int max)
{
    this->max = max;
    return *this;
}

Randomizer &Randomizer::setMin(int min)
{
    this->min = min;
    return *this;
}

int Randomizer::getRandomNumber()
{
    std::uniform_int_distribution<int> distrib(this->min, this->max);
    return distrib(gen);
}

int Randomizer::getRandomNumber(int max)
{

    std::uniform_int_distribution<int> distrib(this->min, max);
    return distrib(gen);
    //    int old_max = this->max;
    //    this->max = max;
    //    int rand = this->getRandomNumber();
    //    this->max = old_max;
    //    return rand;
}

char Randomizer::getRandomSymbol()
{
    int random_number = this->getRandomNumber(this->_alph.size() - 1);
    return this->_alph[random_number];
}

void Randomizer::debugPrint()
{
    std::cout << "-----------Randomizer debug output-----------" << std::endl;
    std::cout << "Alphabet size: " << this->_alph.size() << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "-----------Randomizer end debug output-----------" << std::endl;
}

std::string Randomizer::getAlphabet()
{
    return _alph;
}

std::vector<int> Randomizer::generateKey(size_t size)
{
    //    std::vector<int>  key;
    //    int val = getRandomNumber(10000);
    //    for(int i=0;i<size;i++) {
    //        key.push_back(val);
    //    }

    std::vector<int> key;
    key.reserve(size);
    for (size_t i = 0; i < size; i++)
    {
        key.push_back(getRandomNumber(10000));
    }
    return key;
}
