#ifndef OUTPUTDIREC
#define OUTPUTDIREC

#include "Connector.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
class OutputDirec : public Connector
{
    private: 
    int recursive=0;
    public:
    OutputDirec(int depth) : Connector(depth) {};
    ~OutputDirec() {};
    void addLeftCmd(CommandLine* lhs) {Connector::lhs = lhs;};
    void addRightCmd(CommandLine* rhs) {Connector::rhs = rhs;};
    bool execute(int fDescripIn, int fDescripOut); 
};

#endif
