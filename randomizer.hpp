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
    const std::string& alph;
public:
    Randomizer(std::string&);
    Randomizer& set_max(int max);
    Randomizer& set_min(int min);
    int get_random_number();
    int get_random_number(int max);
    char get_random_symbol();
    std::string get_alph();
    void debug_print();
    std::vector<int> generate_key(size_t size);
};
