#include <iostream>

#include "io.h"
#include "word.h"

using namespace std;

int main()
{
    cout << "a beginning wordle application" << endl;

    IO io;
    Word *word = io.getWord();
    cout << *word << endl;
    delete word;

    cout << "end" << endl;
    return 0;
}