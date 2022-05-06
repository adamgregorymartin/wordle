#ifndef IO_H
#define IO_H

#include <iostream>
#include "word.h"

class IO
{
private:
    void trim(std::string &str);
    bool isAlpha(std::string &str);
    void toLower(std::string &str);

public:
    Word* getWord();
};

#endif
