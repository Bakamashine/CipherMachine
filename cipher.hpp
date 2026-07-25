#pragma once
#include <string>
#include <vector>
#include "alph.hpp"

class Cipher
{
private:
    std::string word;
//    std::vector<std::string> chiphered_vec;
    Alph& alph;

public:
    Cipher(std::string, Alph&);
    std::vector<std::string> get_chiphered_vec();
    Cipher* set_word(std::string);

};
