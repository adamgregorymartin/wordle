#include "word.h"

using namespace std;

Word::Word(string &str)
{
    char i = 0;
    for (const char &c : str)
    {
        chars[i++] = c;
    }
}

Word::Word(char chars[6])
{
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        this->chars[i] = chars[i];
    }
}

bool Word::isValid(string &lowerAlphaStr)
{
    // str is composed of only lowercase letters
    return lowerAlphaStr.length() == Word::LENGTH;
}

ostream &operator<<(ostream &stream, const Word &word)
{
    for (const char &c : word.chars)
    {
        stream << c;
    }
    return stream;
}
