#include <iostream>

#include "io.h"
#include "word.h"
#include "word_comparer.h"

using namespace std;

int main()
{
    cout << "Wordle" << endl;

    Word solution("apple");

    cout << "Enter a guess: ";
    IO io;
    Word *guess = io.getWord();

    cout << "You guessed: " << *guess << endl;

    WordComparer comparer;
    comparer.initSolution(&solution);
    string feedback = comparer.getGuessFeedback(guess);

    cout << "Guess feedback: " << feedback << endl;

    delete guess;

    cout << "end" << endl;
    return 0;
}