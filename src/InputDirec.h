#ifndef INPUTDIREC
#define INPUTDIREC
#include "Connector.h"

class InputDirec : public Connector
{
    private:
    int recursive = 0;
    public:
    InputDirec(int depth) : Connector(depth) {};
    ~InputDirec() {};
    void addLeftCmd(CommandLine* lhs) {};
    void addRightCmd(CommandLine* rhs) {};
    bool execute(int fDescripIn, int fDescripOut);
};
#endif
