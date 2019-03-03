#ifndef OUTPUTAPPEND
#define OUTPUTAPPEND

#include "Connector.h"
class OutputAppend : public Connector
{
    private:
    int recursive = 0;
    public:
    OutputAppend(int depth) : Connector(depth) {};
    ~OutputAppend() {};
    void addLeftCmd(CommandLine* lhs) {};
    void addRightCmd(CommandLine* rhs) {};
    bool execute(int fDescripIn, int fDescripOut);
};

#endif
