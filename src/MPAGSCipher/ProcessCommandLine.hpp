#ifndef MPAGSCIPHER_PROCESSCOMMANDLINE_HPP
#define MPAGSCIPHER_PROCESSCOMMANDLINE_HPP

#include <string>
#include <vector>
#include <iostream>

bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName, bool& encrypt, std::size_t& cipher_key);

#endif // MPAGSCIPHER_PROCESSCOMMANDLINE_HPP