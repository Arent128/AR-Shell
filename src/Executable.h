#ifndef EXECUTABLE_H
#define EXECUTABLE_H

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
#include <string>
#include "CommandLine.h"
#include <iostream>

//class inherit from CommandLine base class
class Executable : public CommandLine
{	
   private:
   //creating argument variable
   std::string args;
   //creating args size
   int numberOfArgs;
   std::string tmp;
   char** cArgs;

   public:

   //executable constructor
   Executable()
   {

   };
   Executable(std::string args, int numberOfArgs) 
   {
      this->args = args;
      this->numberOfArgs = numberOfArgs;
   };

   ~Executable()
   {
   
   };
   void createArgList(std::string args);
   bool execute(int fDescripIn, int fDescripOut);
};

#endif
