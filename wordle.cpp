#include <iostream>

#include "io.h"
#include "word.h"

using namespace std;

int main()
{
    cout << "a beginning wordle application" << endl;

    Word solution("apple");
    IO io;
    Word *guess = io.getWord();
    cout << *guess << endl;
    delete guess;

    cout << "end" << endl;
    return 0;
}