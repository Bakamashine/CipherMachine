#pragma once
#include "randomizer.hpp"
#include <string_view>
#include <vector>
class Alph
{
private:
    const std::string &alph;
    const Randomizer& link_rand;

public:
    Alph(std::string&, Randomizer&);
    std::string get_utf8_by_index(int);
    int get_index(char value);
    std::string get_utf8(const char);
    static void print_vector(std::vector<std::string>&);
    std::string get_alph();
    void set_uppercase_alph();
    void set_lowercase_alph();
    std::string lowercase(const std::string*);
    std::string uppercase(const std::string*);

};
