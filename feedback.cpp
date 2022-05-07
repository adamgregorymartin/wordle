#include "feedback.h"

using namespace std;

Feedback::Feedback()
{
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        correct[i] = UNKNOWN;
        misplaced[i] = UNKNOWN;
    }
    for (char i = 0; i < Word::N_LETTERS; ++i)
    {
        freqMin[i] = 0;
        freqMax[i] = Word::LENGTH;
    }
}

void Feedback::reset()
{
    for (char i = 0; i < nCorrect; ++i)
    {
        char correctI = correctChanges[i];
        freqMin[Word::lowercaseIndex(correct[correctI])] = 0;
        correct[correctI] = UNKNOWN;
    }
    for (char i = 0; i < nMisplaced; ++i)
    {
        char misplacedI = misplacedChanges[i];
        freqMin[Word::lowercaseIndex(misplaced[misplacedI])] = 0;
        misplaced[misplacedI] = UNKNOWN;
    }
    for (char i = 0; i < nFreqMaxChanges; ++i)
    {
        char freqMaxI = freqMaxChanges[i];
        freqMax[freqMaxI] = Word::LENGTH;
    }
    nCorrect = 0;
    nMisplaced = 0;
    nFreqMaxChanges = 0;
}

void Feedback::addCorrectChar(char correctChar, char i)
{
    correct[i] = correctChar;
    correctChanges[nCorrect++] = i;
    freqMin[Word::lowercaseIndex(correctChar)] += 1;
}

void Feedback::addMisplacedChar(char misplacedChar, char i)
{
    misplaced[i] = misplacedChar;
    misplacedChanges[nMisplaced++] = i;
    freqMin[Word::lowercaseIndex(misplacedChar)] += 1;
}

void Feedback::setCharFreqMax(char lowercaseIndex)
{
    freqMax[lowercaseIndex] = freqMin[lowercaseIndex];
    freqMaxChanges[nFreqMaxChanges++] = lowercaseIndex;
}

ostream &operator<<(ostream &stream, const Feedback &feedback)
{
    const char STR_LENGTH = Word::LENGTH * 2 - 1;
    for (char i = 0; i < STR_LENGTH; ++i)
    {
        if (i % 2)
        {
            stream << ' ';
        }
        else
        {
            char charI = i / 2;
            if (feedback.correct[charI] != Feedback::UNKNOWN)
            {
                stream << Feedback::CORRECT;
            }
            else if (feedback.misplaced[charI] != Feedback::UNKNOWN)
            {
                stream << Feedback::MISPLACED;
            }
            else
            {
                stream << '_';
            }
        }
    }
    return stream;
}
