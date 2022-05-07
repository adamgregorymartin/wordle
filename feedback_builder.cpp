#include "feedback_builder.h"

using namespace std;

void FeedbackBuilder::reset()
{
    if (solution)
    {
        for (char i = 0; i < Word::LENGTH; ++i)
        {
            solutionFreq[solution->charLowercaseIndex(i)] = 0;
        }
    }
}

FeedbackBuilder::FeedbackBuilder()
{
    for (char i = 0; i < Word::N_LETTERS; ++i)
    {
        solutionFreq[i] = 0;
    }
}

void FeedbackBuilder::init(Word *solution)
{
    reset();
    this->solution = solution;
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        solutionFreq[solution->charLowercaseIndex(i)] += 1;
    }
}

void FeedbackBuilder::buildFeedback(Word *guess, Feedback *feedback)
{
    feedback->reset();
    // Build Feedback object
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        if (guess->charAt(i) == solution->charAt(i))
        {
            feedback->addCorrectChar(guess->charAt(i), i);
            solutionFreq[guess->charLowercaseIndex(i)] -= 1;
        }
    }
    for (char i = 0; i < Word::LENGTH; ++i)
    {
        if (!feedback->isCorrectAt(i))
        {
            if (solutionFreq[guess->charLowercaseIndex(i)] > 0)
            {
                feedback->addMisplacedChar(guess->charAt(i), i);
                solutionFreq[guess->charLowercaseIndex(i)] -= 1;
            }
            else
            {
                feedback->setCharFreqMax(guess->charLowercaseIndex(i));
            }
        }
    }
    // Reset solutionFreq (linear in the number of changes)
    for (char i = 0; i < feedback->getNCorrect(); ++i)
    {
        solutionFreq[guess->charLowercaseIndex(feedback->getCorrectIndices()[i])] += 1;
    }
    for (char i = 0; i < feedback->getNMisplaced(); ++i)
    {
        solutionFreq[guess->charLowercaseIndex(feedback->getMisplacedIndices()[i])] += 1;
    }
}
