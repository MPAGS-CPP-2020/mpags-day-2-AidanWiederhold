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
        std::size_t cipherChar_pos{alphabet.find(cipherChar)}; //find the index of the cipherChar in the alphabet
        if(encrypt)
        {
            if(cipherChar_pos+key>25) //if the sum of the cipherChar position and the key is greater than 25 then you need to wrap round to the start of the alphabet
            {
                output_string += alphabet[(cipherChar_pos+key)-26];
            }
            else
            {
                output_string += alphabet[cipherChar_pos+key];
            }
        }
        else //perform decryption
        {
            if(cipherChar_pos<key) //if the key is greater than the cipherChar position then you need to wrap round to the end of the alphabet
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