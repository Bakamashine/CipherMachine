#include "randomizer.hpp"
#include <random>
#include <iostream>


Randomizer::Randomizer(std::string& _alph) : alph(_alph), gen(rd())
{

}

Randomizer& Randomizer::set_max(int max)
{
    this->max = max;
    return *this;
}

Randomizer& Randomizer::set_min(int min)
{
    this->min = min;
    return *this;
}

int Randomizer::get_random_number()
{
    std::uniform_int_distribution<int> distrib(this->min, this->max);
    return distrib(gen);
}

int Randomizer::get_random_number(int max)
{

        std::uniform_int_distribution<int> distrib(this->min, max);
return distrib(gen);
//    int old_max = this->max;
//    this->max = max;
//    int rand = this->get_random_number();
//    this->max = old_max;
//    return rand;
}

char Randomizer::get_random_symbol()
{
    int random_number = this->get_random_number(this->alph.size() - 1);
    return this->alph[random_number];
}

void Randomizer::debug_print()
{
    std::cout << "-----------Randomizer debug output-----------" << std::endl;
    std::cout << "Alph size: " << this->alph.size() << std::endl;
    std::cout << "Max: " << max << std::endl;
    std::cout << "Min: " << min << std::endl;
    std::cout << "-----------Randomizer end debug output-----------" << std::endl;
}

std::string Randomizer::get_alph()
{
    return alph;
}

std::vector<int> Randomizer::generate_key(size_t size)
{
//    std::vector<int>  key;
//    int val = get_random_number(10000);
//    for(int i=0;i<size;i++) {
//        key.push_back(val);
//    }

    std::vector<int> key;
    key.reserve(size);
    for (size_t i = 0; i < size; i++) {
        key.push_back(get_random_number(10000));
    }
    return key;
}
