// Standard Library includes
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

// For std::isalpha and std::isupper
#include <cctype>

// Include the transliterator
#include "TransformChar.hpp"
#include "ProcessCommandLine.hpp"
#include "runCaesarCipher.hpp"

// Main function of the mpags-cipher program
int main(int argc, char* argv[])
{
  // Convert the command-line arguments into a more easily usable form
  const std::vector<std::string> cmdLineArgs {argv, argv+argc};

  // Options that might be set by the command-line arguments
  bool helpRequested {false};
  bool versionRequested {false};
  std::string inputFile {""};
  std::string outputFile {""};
  bool crypt{true};
  std::size_t key{3};
  // Process command line arguments - ignore zeroth element, as we know this to
  // be the program name and don't need to worry about it
  if(!processCommandLine(cmdLineArgs, helpRequested, versionRequested, inputFile, outputFile, crypt, key))
  {
    std::cerr << "Command line error, please use -h option to understand how to use the programme." << std::endl;
    return 1;
  }

  std::ifstream in_file{inputFile};
  bool ok_to_read = in_file.good();

  std::ofstream out_file{outputFile};
  bool ok_to_write = out_file.good();

  // Handle help, if requested
  if (helpRequested) {
    // Line splitting for readability
    std::cout
      << "Usage: mpags-cipher [-i <file>] [-o <file>]\n\n"
      << "Encrypts/Decrypts input alphanumeric text using classical ciphers\n\n"
      << "Available options:\n\n"
      << "  -h|--help        Print this help message and exit\n\n"
      << "  --version        Print version information\n\n"
      << "  -i FILE          Read text to be processed from FILE\n"
      << "                   Stdin will be used if not supplied\n\n"
      << "  -o FILE          Write processed text to FILE\n"
      << "                   Stdout will be used if not supplied\n\n";
    // Help requires no further action, so return from main
    // with 0 used to indicate success
    return 2;
  }

  // Handle version, if requested
  // Like help, requires no further action,
  // so return from main with zero to indicate success
  if (versionRequested) {
    std::cout << "0.1.0" << std::endl;
    return 3;
  }

  // Initialise variables for processing input text
  char inputChar {'x'};
  std::string inputText {""};

  // If no input file then read input from command line
  // if input file named check it can be opened
  // if it can be opened then use it as input
  // Loop over each character from user input
  // (until Return then CTRL-D (EOF) pressed)
  if(inputFile.empty())
  {
    while(std::cin >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }
  else if(!ok_to_read)
  {
    std::cerr << "Could not open input file!" << std::endl;
    return 4;
  }
  else
  {
    while(in_file >> inputChar)
    {
      inputText += transformChar(inputChar);
    }
  }

  std::string outputText{runCaesarCipher(inputText, key, crypt)};

  if(outputFile.empty())
  {
    std::cout << outputText << std::endl;
  }
  else if(!ok_to_write)
  {
    std::cerr << "Could not open output file!" << std::endl;
    return 5;
  }
  else
  {
    out_file << outputText << "\n";
  }
  // No requirement to return from main, but we do so for clarity
  // and for consistency with other functions
  return 0;
}