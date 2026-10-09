#pragma once
#include "randomizer.hpp"
#include <vector>
class Alphabet
{
private:
    const std::string &_alph;
    const Randomizer &_link_rand;

public:
    Alphabet(std::string &, Randomizer &);
    std::string get_utf8_by_index(int);
    int get_index(char value);
    std::string get_utf8(const char);
    static void print_vector(std::vector<std::string> &);
    std::string getAlphabet();
    void set_uppercase_alph();
    void set_lowercase_alph();
    std::string lowerCase(const std::string *);
    std::string upperCase(const std::string *);
};
