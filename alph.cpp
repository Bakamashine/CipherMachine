#include<sstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <stdexcept>
#include "alph.hpp"
#include <format>
#include <iomanip>
#include <vector>
#include <cctype>

Alph::Alph(std::string &_alph, Randomizer &_rand): alph(_alph), link_rand(_rand)
{

}
std::string Alph::get_utf8(const char val)
{

    std::stringstream str_stream;
    std::u8string utf8_char(1, val);
//    for (unsigned char byte : val) {
    for (char8_t byte : utf8_char)
    {
        str_stream << "0x"
                   << std::hex
                   << std::uppercase
                   << std::setw(2)
                   << std::setfill('0')
                   << static_cast<int>(byte)
                   << " ";
    }
    return str_stream.str();
}

std::string Alph::get_utf8_by_index(int val)
{
    if (val > alph.size())
    {
        throw std::invalid_argument("Val greater than array size");
    }
    return get_utf8(alph[val]);
//    return get_utf8(std::string_view(&alph[val], 1));

}
int Alph::get_index(char value)
{
    for (int i = 0; i < alph.size(); i++)
    {
        if (alph[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void Alph::print_vector(std::vector<std::string>& vec)
{
    for (int i = 0; i<vec.size(); i++)
    {
        std::cout << vec[i] << "|";
    }
    std::cout << std::endl;

}

std::string Alph::get_alph()
{
    return alph;
}
//void Alph::set_uppercase_alph()
//{
//    for(char& val : alph)
//    {
//        val = static_cast<char>(std::toupper(static_cast<unsigned char>(val)));
//    }
//
//}
//void Alph::set_lowercase_alph()
//{
//    for(char& val : alph)
//    {
//        val = static_cast<char>(std::tolower(static_cast<unsigned char>(val)));
//    }
//
//}

std::string Alph::uppercase(const std::string* _val)
{
    std::string new_str;
    for(char val : *_val)
    {
        new_str += static_cast<char>(std::toupper(static_cast<unsigned char>(val)));
    }
    return new_str;
}

std::string Alph::lowercase(const std::string* _val)
{
    std::string new_str;
    for(char val : *_val)
    {
        new_str += static_cast<char>(std::tolower(static_cast<unsigned char>(val)));
    }
    return new_str;
}
