#ifndef FEEDBACK_H
#define FEEDBACK_H

#include "word.h"

class Feedback
{
private:
    char correct[Word::LENGTH];
    char misplaced[Word::LENGTH];
    char freqMin[Word::N_LETTERS];
    char freqMax[Word::N_LETTERS];

    char correctChanges[Word::LENGTH];
    char misplacedChanges[Word::LENGTH];
    char freqMaxChanges[Word::LENGTH];
    char nCorrect = 0;
    char nMisplaced = 0;
    char nFreqMaxChanges = 0;

public:
    static const char UNKNOWN = '_';
    static const char CORRECT = 'G';
    static const char MISPLACED = 'Y';

    Feedback();
    void reset();
    void addCorrectChar(char correctChar, char i);
    void addMisplacedChar(char misplacedChar, char i);
    void setCharFreqMax(char lowercaseIndex);

    char isCorrectAt(char i) { return correct[i] != UNKNOWN; }
    char (&getCorrectIndices())[Word::LENGTH] { return correctChanges; }
    char getNCorrect() { return nCorrect; }
    char (&getMisplacedIndices())[Word::LENGTH] { return misplacedChanges; }
    char getNMisplaced() { return nMisplaced; }

    bool isCorrect() { return nCorrect == Word::LENGTH; }

    // bool isConsistentWith(Word *word);
    friend std::ostream &operator<<(std::ostream &stream, const Feedback &feedback);
};

std::ostream &operator<<(std::ostream &stream, const Feedback &feedback);

#endif