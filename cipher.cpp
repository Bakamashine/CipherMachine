#include "cipher.h"
#include <iostream>
#include <string>

Cipher::Cipher(std::string word, Alphabet &al) : _word(word), _alph(al)
{
}

std::vector<std::string> Cipher::getCipheredVec()
{
    std::vector<std::string> ciphered_vec;
    std::string temp_str;
    for (int i = 0; i < _word.size(); i++)
    {
        temp_str = _alph.get_utf8(static_cast<const char>(_word[i]));
#ifdef DEBUG
        std::cout
            << "Word: "
            << _word[i]
            << "\t"
            << temp_str
            << std::endl;
//            if (temp_str.size() > 4) {
//                std::cout << "Not english alphabet" << std::end;
//                return -1;
//            }
#endif
        ciphered_vec.push_back(temp_str);
    }

    return ciphered_vec;
}

Cipher *Cipher::setWord(std::string val)
{
    _word = val;
    return this;
}
