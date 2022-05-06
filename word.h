#ifndef WORD_H
#define WORD_H

#include <iostream>

class Word
{
public:
    static const char LENGTH = 5;

private:
    char chars[LENGTH];

public:
    Word(std::string &str);
    Word(char chars[6]);
    static bool isValid(std::string &lowerAlphaStr);
    friend std::ostream &operator<<(std::ostream &stream, const Word &word);
};

std::ostream &operator<<(std::ostream &stream, const Word &word);

#endif