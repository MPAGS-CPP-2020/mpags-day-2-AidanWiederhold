#include <string>
#include <cctype>

// Include the header
#include "TransformChar.hpp"

std::string transformChar(const char in_char)
{
  std::string outString{""};
  // Uppercase alphabetic characters
  if (std::isalpha(in_char))
  {
    outString = std::toupper(in_char);
    return outString;
  }
  // Transliterate digits to English words
  switch (in_char)
  {
    case '0':
	    return "ZERO";
    case '1':
	    return "ONE";
    case '2':
	    return "TWO";
    case '3':
	    return "THREE";
    case '4':
	    return "FOUR";
    case '5':
	    return "FIVE";
    case '6':
	    return "SIX";
    case '7':
	    return "SEVEN";
    case '8':
	    return "EIGHT";
    case '9':
	    return "NINE";
  }
  // If the character isn't alphabetic or numeric, DONT add it.
  // Our ciphers can only operate on alphabetic characters.
  return "";
}