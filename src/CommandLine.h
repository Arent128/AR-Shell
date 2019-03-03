#ifndef COMMANDLINE_H
#define COMMANDLINE_H

//CommandLine is the base class of the r-shell.h

class CommandLine 
{
  public:
  //Constructor
  CommandLine() 
  {

  };

  ~CommandLine()
  {
  
  };

  //Pure Virtual Method
  virtual bool execute(int fDescripOut, int fDescripIn)=0;
};

#endif
