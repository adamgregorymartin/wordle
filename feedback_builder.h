#ifndef FEEDBACK_BUILDER_H
#define FEEDBACK_BUILDER_H

#include "word.h"
#include "feedback.h"

class FeedbackBuilder
{
private:
    char solutionFreq[Word::N_LETTERS];
    Word *solution = nullptr;

    void reset();

public:
    FeedbackBuilder();
    void init(Word *solution);
    // void buildFeedback(Word *guess, Feedback *feedback, std::string str);
    void buildFeedback(Word *guess, Feedback *feedback);
};

#endif