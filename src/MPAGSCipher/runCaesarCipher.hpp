#ifndef MPAGSCIPHER_RUNCAESARCIPHER_HPP
#define MPAGSCIPHER_RUNCAESARCIPHER_HPP

#include <string>
#include <iostream>

std::string runCaesarCipher(const std::string& inputText, const std::size_t key, const bool encrypt);

#endif // MPAGSCIPHER_RUNCAESARCIPHER_HPP