#ifndef PIPE
#define PIPE
#include "Connector.h"

class Pipe : public Connector
{
    public:
    Pipe(int depth) : Connector(depth) {};
    ~Pipe() {};
    void addLeftCmd(CommandLine* lhs) {Connector::lhs = lhs;};
    void addRightCmd(CommandLine* rhs) {Connector::rhs = rhs;};
    bool execute(int fDescripIn, int fDescripOut);
};

#endif
