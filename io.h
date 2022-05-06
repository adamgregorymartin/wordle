#ifndef IO_H
#define IO_H

#include <iostream>

class IO
{
private:
    void trim(std::string &str);
    bool isAlpha(std::string &str);
    void toLower(std::string &str);

public:
    std::string getWord();
};

#endif
