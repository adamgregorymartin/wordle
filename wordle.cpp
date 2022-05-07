#include <iostream>

#include "io.h"
#include "word.h"
#include "feedback_builder.h"
#include "feedback.h"

using namespace std;

int main()
{
    // rename WordComparer to FeedbackGenerator
    cout << "Wordle" << endl;

    Word solution("apple");

    cout << "Enter a guess: ";
    IO io;
    Word *guess = io.getWord();

    cout << "You guessed: " << *guess << endl;

    FeedbackBuilder builder;
    Feedback feedback;
    builder.init(&solution);
    builder.buildFeedback(guess, &feedback);

    cout << "Guess feedback: " << feedback << endl;

    delete guess;

    cout << "end" << endl;
    return 0;
}