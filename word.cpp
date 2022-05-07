#include "word.h"

using namespace std;

Word::Word(string str)
{
    char i = 0;
    for (const char &c : str)
    {
        chars[i++] = c;
    }
}

bool Word::isValid(string &lowerAlphaStr)
{
    // str is composed of only lowercase letters
    return lowerAlphaStr.length() == Word::LENGTH;
}

const char &Word::charAt(const char &i) const
{
    return chars[i];
}

ostream &operator<<(ostream &stream, const Word &word)
{
    for (const char &c : word.chars)
    {
        stream << c;
    }
    return stream;
}
