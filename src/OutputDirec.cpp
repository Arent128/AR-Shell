#include "OutputDirec.h"
#include <iostream>

bool OutputDirec::execute(int fDescripIn, int fDescripOut)
{
    int fdout;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;
    if(Connector::getInFileName() != "")
    {
      this->setDepth(-5);
      recursive++;
    }
    if(this->getDepth() == -5 && recursive == 1)
    {
        fdout = open(Connector::getOutFileName().c_str(), O_WRONLY | O_TRUNC | O_CREAT, mode);
        bool result = Connector::singleCmd->execute(fDescripIn, fdout);
        close(fdout);
        return result;
    }
    else if(this->getDepth() == -5 && recursive > 1)
    {
        fdout = open(Connector::getOutFileName().c_str(), O_WRONLY | O_TRUNC | O_CREAT, mode);
        bool result = Connector::singleCmd->execute(fDescripIn, fDescripOut);
        close(fdout);
        return result;
    }
    else if(recursive == 0)
    {
        fdout = open(Connector::getOutFileName().c_str(), O_WRONLY | O_TRUNC | O_CREAT, mode);
        bool result = Connector::singleCmd->execute(fDescripIn, fdout);
        close(fdout);
        return result;
    }
    else
    {
        fdout = open(Connector::getOutFileName().c_str(), O_WRONLY |  O_TRUNC | O_CREAT, mode);
        bool result = Connector::singleCmd->execute(fDescripIn, fDescripOut);
        close(fdout);
        return result;
    }
}
