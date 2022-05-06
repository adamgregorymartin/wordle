#include "io.h"

//#include "word.h"

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
    for (string::iterator it = str.begin(); it != str.end(); ++it)
    {
        if ((*it < 'a' || *it > 'z') and (*it < 'A' || *it > 'Z'))
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

string IO::getWord()
{
    string word;
    while (true)
    {
        cin >> word;
        IO::trim(word);
        if (!IO::isAlpha(word)) continue;
        toLower(word);
        if (word.length() == 5) break; // TODO change to a call to WORD class
    }
    return word;
}

/*
Word readGuess()
{
    string guess;
    do
    {
        cin >> guess;
        trim(guess);
    } while (!isValidGuess(guess));
    convertToLowercase(guess);
    return Word(guess);
}
*/