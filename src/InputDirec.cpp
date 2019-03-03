#include "InputDirec.h"

bool InputDirec::execute(int fDescripIn, int fDescripOut)
{ 
    int fdin;
    mode_t mode = S_IRUSR | S_IWUSR | S_IRGRP | S_IROTH;

    if(Connector::getInFileName() != "")
    {
      this->setDepth(-5);
      recursive++;
    }
    if(this->getDepth() == -5 && recursive == 1)
    {
        fdin = open(Connector::getOutFileName().c_str(), O_RDONLY, mode);
        bool result = Connector::singleCmd->execute(fdin, fDescripOut);
        close(fdin);
        return result;
    }
    else if(this->getDepth() == -5 && recursive > 1)
    {
        fdin = open(Connector::getOutFileName().c_str(), O_RDONLY, mode);
        bool result = Connector::singleCmd->execute(fDescripIn, fDescripOut);
        close(fdin);
        return result;
    }
    else if(recursive == 0)
    {
        fdin = open(Connector::getOutFileName().c_str(), O_RDONLY, mode);
        bool result = Connector::singleCmd->execute(fdin, fDescripOut);
        close(fdin);
        return result;
    }
    else
    {
        fdin = open(Connector::getOutFileName().c_str(), O_RDONLY, mode);
        bool result = Connector::singleCmd->execute(fDescripIn, fDescripOut);
        close(fdin);
        return result;
    }
}
