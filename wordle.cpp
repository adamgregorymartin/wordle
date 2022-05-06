#include <iostream>

#include "io.h"

using namespace std;

int main()
{
    cout << "a beginning wordle application" << endl;

    IO io;
    string word = io.getWord();
    cout << word << endl;

    cout << "end" << endl;
    return 0;
}