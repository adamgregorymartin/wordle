#ifndef WORD_COMPARER
#define WORD_COMPARER

#include "word.h"

class WordComparer
{
private:
    static const char N_LETTERS = 26;
    char charMap[N_LETTERS];
    char clues[Word::LENGTH];
    Word *solution = nullptr;

    void resetSolution();
    void resetGuess(Word *guess);

public:
    WordComparer();
    static char charIndex(Word *word, char i);
    void initSolution(Word *solution);
    std::string getGuessFeedback(Word *guess);
};

#endif