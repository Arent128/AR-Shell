#ifndef TESTFUNC_H
#define TESTFUNC_H

#include <sys/stat.h>
#include "CommandLine.h"
#include <string>

class TestFunc : public CommandLine
{
    private:
    std::string input;
    int numberOfArgs;
    std::string arg;
    int flag;
    std::string tmp;
    public:

    TestFunc() {};
    TestFunc(std::string input, int numberOfArgs) {this->input = input; this->numberOfArgs = numberOfArgs;};
   ~TestFunc() {};
    int createArgs();
    bool execute(int fDescripIn, int fDescripOut);
};

#endif
