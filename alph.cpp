#include <sstream>
#include <iostream>
#include <stdexcept>
#include "alph.h"
#include <vector>
#include <cctype>
#include <string>
#include <iomanip>

Alphabet::Alphabet(std::string &_alph, Randomizer &rand) : _alph(_alph), _link_rand(rand)
{
}
std::string Alphabet::get_utf8(const char val)
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

std::string Alphabet::get_utf8_by_index(int val)
{
    if (val > _alph.size())
    {
        throw std::invalid_argument("Val greater than array size");
    }
    return get_utf8(_alph[val]);
    //    return get_utf8(std::string_view(&_alph[val], 1));
}
int Alphabet::get_index(char value)
{
    for (int i = 0; i < _alph.size(); i++)
    {
        if (_alph[i] == value)
        {
            return i;
        }
    }
    return -1;
}

void Alphabet::print_vector(std::vector<std::string> &vec)
{
    for (int i = 0; i < vec.size(); i++)
    {
        std::cout << vec[i] << "|";
    }
    std::cout << std::endl;
}

std::string Alphabet::getAlphabet()
{
    return _alph;
}
// void Alphabet::set_uppercase_alph()
//{
//     for(char& val : _alph)
//     {
//         val = static_cast<char>(std::toupper(static_cast<unsigned char>(val)));
//     }
//
// }
// void Alphabet::set_lowercase_alph()
//{
//     for(char& val : _alph)
//     {
//         val = static_cast<char>(std::tolower(static_cast<unsigned char>(val)));
//     }
//
// }

std::string Alphabet::upperCase(const std::string *_val)
{
    std::string new_str;
    for (char val : *_val)
    {
        new_str += static_cast<char>(std::toupper(static_cast<unsigned char>(val)));
    }
    return new_str;
}

std::string Alphabet::lowerCase(const std::string *_val)
{
    std::string new_str;
    for (char val : *_val)
    {
        new_str += static_cast<char>(std::tolower(static_cast<unsigned char>(val)));
    }
    return new_str;
}
