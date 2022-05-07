#include "word_comparer.h"

using namespace std;

void WordComparer::resetGuess(Word *guess)
{
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        if (clues[i] > 0)
        {
            charMap[charIndex(guess, i)] -= 1;
        }
    }
}

void WordComparer::resetSolution()
{
    if (solution)
    {
        for (char i = 0; i < Word::LENGTH; ++i)
        {
            charMap[charIndex(solution, i)] -= 1;
        }
    }
}

WordComparer::WordComparer()
{
    for (char i = 0; i < N_LETTERS; ++i)
    {
        charMap[i] = 0;
    }
}

char WordComparer::charIndex(Word *word, char i)
{
    return word->charAt(i) - 'a';
}

void WordComparer::initSolution(Word *solution)
{
    resetSolution();
    this->solution = solution;
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        charMap[charIndex(solution, i)] += 1;
    }
}

std::string WordComparer::getGuessFeedback(Word *guess)
{
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        if (guess->charAt(i) == solution->charAt(i))
        {
            clues[i] = 2;
            charMap[charIndex(guess, i)] -= 1;
        }
        else
        {
            clues[i] = 0;
        }
    }
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        if (clues[i] != 2 && charMap[charIndex(guess, i)] > 0)
        {
            clues[i] = 1;
            charMap[charIndex(guess, i)] -= 1;
        }
    }
    WordComparer::resetGuess(guess);
    string feedback = "_ _ _ _ _";
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        switch (clues[i])
        {
        case 1:
            feedback[i * 2] = 'Y';
            break;
        case 2:
            feedback[i * 2] = 'G';
            break;
        }
    }
    return feedback;
}
