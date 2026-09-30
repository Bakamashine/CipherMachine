#include <iostream>
#include "randomizer.h"
#include "alph.h"
#include "cipher.h"
#include "numbers.h"
#include <sstream>
#include <fstream>
#define REMOVE_SYMBOLS(value)                              \
    do                                                     \
    {                                                      \
        (value).erase(                                     \
            std::remove_if((value).begin(), (value).end(), \
                           isRemovableSymbol),             \
            (value).end());                                \
    } while (0)
using ll = long long;
/**
    ������ �����: ���� (PINYA)

    D09F | D0AB | D09D | D0AF

    //// original utf-8 (10) * (0x44)first utf-8 (16) D * 9 * (0x46)second utf-8 (16) F * 208 191  (utf-8 �-small (10))


    original utf-8 (16)

    �
    D09F
    original 208 159 utf-8 (10)
    0x44
    0x46
208 191  (utf-8 �-small (10))
random_value (on_array)

    ///
    Revert:
    D0AF | D09D | D0AB | D09F
*/
using namespace std;
const std::string input_file_name = "input.txt";
const std::string output_file_name = "output.txt";

inline char isRemovableSymbol(char c)
{
    return c == ' ' || c == ',' || c == ';' || c == '!' || c == '\n';
}

int main()
{
    std::ifstream in(input_file_name);
    std::ofstream out(output_file_name, std::ios::out);
    std::string text;

    if (!in.is_open())
    {
        std::cout << "File is not found: " << input_file_name << std::endl;
        std::cout << "Enter your text: ";
        getline(cin, text);
#ifdef _DEBUG
        std::cout << "Default text: " << text << std::endl;
#endif
        REMOVE_SYMBOLS(text);
    }
    else
    {
        std::string temp_str;
        while (std::getline(in, temp_str))
        {
            REMOVE_SYMBOLS(temp_str);
            text += temp_str;
        }
    }
    std::string alph = "abcdefghijklmnopqrstuvwxyz";
    Randomizer *class_rand = new Randomizer(alph);
    Alphabet *class_alph = new Alphabet(alph, *class_rand);

    std::vector<int> narray = class_rand->generateKey(text.size());
    //    int narray_size = sizeof(narray)/sizeof(narray[0]);

    std::cout << "Key: ";
    std::stringstream stream;
    for (int v : narray)
    {
        std::cout << v;
        stream << v;
#ifdef DEBUG
        std::cout << v << "|";
#endif // DEBUG
    }
    std::cout << std::endl;

    std::cout << "Your text: " << text << std::endl;

    std::string word_lower = class_alph->lowerCase(&text);
    std::string word_upper = class_alph->upperCase(&text);
#ifdef DEBUG
    std::cout << "word_low: " << word_lower << std::endl;
    std::cout << "word_upper: " << word_upper << std::endl;
#endif // DEBUG
    Cipher *cipher = new Cipher(word_upper, *class_alph);

    std::vector<std::string> ciphered_upper_vec = cipher->getCipheredVec();
    std::vector<std::string> ciphered_lower_vec = cipher->setWord(word_lower)->getCipheredVec();

#ifdef DEBUG
    Alphabet::print_vector(ciphered_upper_vec);
    Alphabet::print_vector(ciphered_lower_vec);
#endif

    Numbers *_numbers = new Numbers();
    std::vector<ll> __val;
    if (ciphered_upper_vec.size() == ciphered_lower_vec.size())
    {
        for (int i = 0; i < ciphered_lower_vec.size(); i++)
        {
            __val.push_back(_numbers->multiplicationHex(ciphered_lower_vec[i], ciphered_upper_vec[i]));
        }
    }
    else
    {
        std::cout << "-1";
        return -1;
    }

    if (__val.size() != narray.size())
    {
        return -2;
    }

    for (int i = 0; i < __val.size(); i++)
    {
        __val[i] *= narray[i];
    }

#ifdef DEBUG
    for (ll v : __val)
    {
        std::cout << "v: " << v << std::endl;
    }
#endif

    std::stringstream final_str_stream;
    final_str_stream << "--------------Your text--------------" << std::endl;
    for (ll v : __val)
    {
        final_str_stream << v << class_rand->getRandomSymbol();
    }
    final_str_stream << " key: " << stream.str() << std::endl;
    if (in.is_open())
    {
        out << final_str_stream.str();
    }
    in.close();
    out.close();
    delete _numbers;
    delete cipher;
    delete class_alph;
    delete class_rand;
    return 0;
}
