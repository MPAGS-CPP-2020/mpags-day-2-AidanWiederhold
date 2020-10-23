#include <string>
#include <vector>
#include <iostream>

// Include the header
#include "ProcessCommandLine.hpp"

bool processCommandLine(const std::vector<std::string>& args, bool& helpRequested, bool& versionRequested, std::string& inputFileName, std::string& outputFileName, bool& encrypt, std::size_t& cipher_key)
{
  // Add a typedef that assigns another name for the given type for clarity
  typedef std::vector<std::string>::size_type size_type;
  const size_type nCmdLineArgs {args.size()};
  for (size_type i {1}; i < args.size(); ++i)
  {
    if (args[i] == "-h" || args[i] == "--help") 
    {
      helpRequested = true;
    }
    else if (args[i] == "--version")
    {
      versionRequested = true;
    }
    else if (args[i] == "-i")
    {
      // Handle input file option
      // Next element is filename unless -i is the last argument
      if (i == nCmdLineArgs-1)
      {
        std::cerr << "[error] -i requires a filename argument" << std::endl;
        return false;
      }
      else
      {
        // Got filename, so assign value and advance past it
        inputFileName = args[i+1];
        ++i;
      }
    }
    else if (args[i] == "-o")
    {
      // Handle output file option
      // Next element is filename unless -o is the last argument
      if (i == nCmdLineArgs-1)
      {
        std::cerr << "[error] -o requires a filename argument" << std::endl;
        return false;
      }
      else
      {
        // Got filename, so assign value and advance past it
        outputFileName = args[i+1];
        ++i;
      }
    }
    else if(args[i]=="--encrypt")
    {
        if (i == nCmdLineArgs-1)
        {
            std::cerr << "[error] --encrypt requires you to follow it with either true or false" << std::endl;
            return false;
        }
        else if(args[i+1]=="true")
        {
            encrypt = true;
            ++i;
        }
        else if(args[i+1]=="false")
        {
            encrypt = false;
            ++i;
        }
        else
        {
            std::cerr << "[error] --encrypt requires you to follow it with either true or false" << std::endl;
            return false;
        }
    }
    else if(args[i]=="--key")
    {
        if (i == nCmdLineArgs-1)
        {
            std::cerr << "[error] -i requires a key value argument" << std::endl;
            return false;
        }
        else if(std::stoi(args[i+1])<0 || std::stoi(args[i+1])>25)
        {
            //Invalid key
            std::cerr << "[error] The key value must be an integer between 0 and 26 " << std::endl;
            return false;
        }
        else
        {
            cipher_key = std::stoi(args[i+1]);
            ++i;
        }
    }
    else
    {
      // Have an unknown flag to output error message and return non-zero
      // exit status to indicate failure
      std::cerr << "[error] unknown argument '" << args[i] << "'\n";
      return false;
    }
  }
  return true;
}