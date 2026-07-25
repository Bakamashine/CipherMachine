#include "cipher.hpp"
#include <iostream>
#include <string>

Cipher::Cipher(std::string _word, Alph& al): word(_word), alph(al)
{

}

std::vector<std::string> Cipher::get_chiphered_vec()
{
    std::vector<std::string> chiphered_vec;
    std::string temp_str;
    for (int i =0; i<word.size(); i++)
    {
        temp_str = alph.get_utf8(static_cast<const char>(word[i]));
#ifdef DEBUG
        std::cout
                << "Word: "
                << word[i]
                << "\t"
                << temp_str
                << std::endl;
//            if (temp_str.size() > 4) {
//                std::cout << "Not english alphabet" << std::end;
//                return -1;
//            }
#endif
        chiphered_vec.push_back(temp_str);
    }

    return chiphered_vec;
}

Cipher* Cipher::set_word(std::string _val)
{
    word = _val;
    return this;
}


