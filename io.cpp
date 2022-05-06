#include "io.h"

using namespace std;

void IO::trim(string &str)
{
    const string WHITESPACE = " \n\r\t\f\v";
    size_t start = str.find_first_not_of(WHITESPACE);
    size_t end = str.find_last_not_of(WHITESPACE);
    if (start == string::npos) // if start == string::npos, must also == string::npos
        str = "";
    else
        str = str.substr(start, end + 1);
}

bool IO::isAlpha(string &str)
{
    for (const char &c : str)
    {
        if ((c < 'a' || c > 'z') and (c < 'A' || c > 'Z'))
            return false;
    }
    return true;
}

void IO::toLower(string &str)
{
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if (*it >= 'A' && *it <= 'Z')
        {
            *it += ('a' - 'A');
        }
    }
}

Word* IO::getWord()
{
    string str;
    while (true)
    {
        cin >> str;
        IO::trim(str);
        if (!IO::isAlpha(str)) continue;
        toLower(str);
        if (Word::isValid(str)) break;
    }
    Word *word = new Word(str);
    return word;
}
