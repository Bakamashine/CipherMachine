#include <cstdio>
#include <cstdlib>
#include <iostream>
#include "randomizer.hpp"
#include "alph.hpp"
#include "cipher.hpp"
#include <iomanip>
#include "numbers.hpp"
//#include <windows.h>


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




int main()
{

    std::string word;
    std::cout << "Enter your word: ";
    std::cin >> word;
    std::string alph = "abcdefghijklmnopqrstuvwxyz";
    Randomizer* class_rand = new Randomizer(alph);
    Alph *class_alph = new Alph(alph, *class_rand);

    std::vector<int> narray = class_rand->generate_key(word.size());
//    int narray_size = sizeof(narray)/sizeof(narray[0]);

std::cout << "Key: ";
std::stringstream stream;
    for (int v : narray) {
        std::cout << v;
        stream << v;
        #ifdef DEBUG
        std::cout << v << "|";
        #endif // DEBUG
    }
    std::cout << std::endl;

    std::cout << "Your word: " << word << std::endl;


    std::string word_lower = class_alph->lowercase(&word);
    std::string word_upper = class_alph->uppercase(&word);
#ifdef DEBUG
    std::cout << "word_low: " << word_lower << std::endl;
    std::cout << "word_upper: " << word_upper << std::endl;
#endif // DEBUG
    Cipher *ciph = new Cipher(word_upper, *class_alph);


    std::vector<std::string> chiphered_upper_vec = ciph->get_chiphered_vec();
    std::vector<std::string> chiphered_lower_vec = ciph->set_word(word_lower)->get_chiphered_vec();

#ifdef DEBUG
    Alph::print_vector(chiphered_upper_vec);
    Alph::print_vector(chiphered_lower_vec);
#endif

    Numbers* numbers = new Numbers();
    std::vector<ll> __val;
    if (chiphered_upper_vec.size() == chiphered_lower_vec.size())
    {
        for(int i = 0; i<chiphered_lower_vec.size(); i++)
        {
            __val.push_back(numbers->multiplication_hex(chiphered_lower_vec[i], chiphered_upper_vec[i]));
        }
    }
    else
    {
        std::cout << "-1";
        return -1;
    }

//    delete chiphered_lower_vec;
//    delete chiphered_upper_vec;
    delete numbers;
    delete ciph;
    delete class_alph;
    delete class_rand;


    if (__val.size() != narray.size())
    {
        return -2;
    }

    for (int i = 0; i<__val.size(); i++)
    {
        __val[i] *= narray[i];
    }

    #ifdef DEBUG
    for  (ll v: __val)
    {
        std::cout << "v: " << v << std::endl;
    }
    #endif

    std::cout << "--------------Your text--------------" << std::endl;
    for (ll v: __val)
    {
        std::cout << v;
    }
    std::cout << " key: " << stream.str() << std::endl;
    return 0;
}
