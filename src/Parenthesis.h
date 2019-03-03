#ifndef PARENTHESIS_H
#define PARENTHESIS_H
#include "Connector.h"

class Parenthesis : public Connector
{
    public:
      /*Constructors and Deconstructors*/
      Parenthesis() : Connector() {};
      Parenthesis(CommandLine* singleCmd) : Connector(singleCmd) {};
      ~Parenthesis() {};

      /*Public member functions*/
      void addCmd(CommandLine* singleCmd) {Connector::singleCmd = singleCmd;};

      /*Inherited virtual functions*/
      void addLeftCmd(CommandLine* lhs) {};
      void addRightCmd(CommandLine* rhs) {};
      bool execute(int fDescripIn, int fDescripOut);
};
#endif
