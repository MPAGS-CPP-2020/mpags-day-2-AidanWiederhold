#include <string>
#include <iostream>

std::string runCaesarCipher(const std::string& inputText, const std::size_t key, const bool encrypt)
{
    std::string alphabet{"ABCDEFGHIJKLMNOPQRSTUVWXYZ"};
    char cipherChar{'x'};
    std::string output_string{""};
    for(std::size_t l=0;l<inputText.length();++l)
    {
        cipherChar = inputText[l];
        std::size_t cipherChar_pos{alphabet.find(cipherChar)};
        if(encrypt)
        {
            if(cipherChar_pos+key>25)
            {
                output_string += alphabet[(cipherChar_pos+key)-26];
            }
            else
            {
                output_string += alphabet[cipherChar_pos+key];
            }
        }
        else
        {
            if(cipherChar_pos<key)
            {
                output_string += alphabet[cipherChar_pos+26-key];
            }
            else
            {
                output_string += alphabet[cipherChar_pos-key];
            }
        }
    }
    return output_string;
}