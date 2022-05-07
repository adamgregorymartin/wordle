#include "game.h"

using namespace std;

Game::Game(string solutionStr)
{
    io = new IO();
    solution = new Word(solutionStr);
    feedbackBuilder = new FeedbackBuilder();
    feedbackBuilder->init(solution);
    feedback = new Feedback();
}

void Game::play()
{
    cout << "Play Wordle!" << endl;

    short nTurns = 0; // A char won't print correctly without an additional conversion.
    while (!feedback->isCorrect())
    {
        cout << "Enter a guess: ";
        Word *guess = io->getWord();
        // cout << "You guessed: " << *guess << endl;

        feedbackBuilder->buildFeedback(guess, feedback);
        cout << "Guess feedback: " << *feedback << endl;

        delete guess;
        ++nTurns;
    }
    cout << "You solved the puzzle in " << nTurns << " turn" << (nTurns == 1 ? "!" : "s.") << endl;
}

Game::~Game()
{
    delete io;
    delete solution;
    delete feedbackBuilder;
    delete feedback;
}
