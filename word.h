#ifndef WORD_H
#define WORD_H

#include <iostream>

class Word
{
public:
    static const char LENGTH = 5;
    static const char N_LETTERS = 26;

private:
    char chars[LENGTH];

public:
    Word(std::string str);
    static bool isValid(std::string &lowerAlphaStr);
    const char &charAt(const char &i) const;
    char charLowercaseIndex(char &charIndex);
    static char lowercaseIndex(char &c);
    friend std::ostream &operator<<(std::ostream &stream, const Word &word);
};

std::ostream &operator<<(std::ostream &stream, const Word &word);

#endif