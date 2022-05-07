#ifndef GAME_H
#define GAME_H

#include <iostream>

#include "io.h"
#include "word.h"
#include "feedback_builder.h"
#include "feedback.h"

class Game
{
private:
    IO *io;
    Word *solution;
    FeedbackBuilder *feedbackBuilder;
    Feedback *feedback;

public:
    Game(std::string solutionStr);
    void play();
    ~Game();
};

#endif