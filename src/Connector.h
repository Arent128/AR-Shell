#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "CommandLine.h"
#include "Executable.h"
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string>
//Connector class that inherits from CommandLine
class Connector : public CommandLine
{
   protected:
   //Created Left and Ridght Children
   CommandLine* lhs;
   CommandLine* rhs;
   CommandLine* singleCmd;
   std::string outFileName = new char[1];
   std::string inFileName = "";
   int depth = -1;
	
   public:
   /*Constructors and Deconstructors*/
   Connector()
   {

   };

   ~Connector() 
   {
   
   };

   //Assigning to Left and Right Children
   Connector(CommandLine* lhs, CommandLine* rhs) 
   {
      this->lhs = lhs; 
      this->rhs = rhs; 
   };
   //Assigning a single child
   Connector(CommandLine* singleCmd)
   {
      this->singleCmd = singleCmd;
   };
   Connector(int depth) {this->depth = depth;};
   /*Inherited virtual function from CommandLine.h*/
   bool execute()
   {

   };
	
   //Virtual Void for the commandline input of left and right children
   virtual void addLeftCmd(CommandLine* lhs) = 0;
   virtual void addRightCmd(CommandLine* rhs) = 0;
   void addInFile(const char* inFileName) {this->inFileName = inFileName;};
   void addOutFile(const char* outFileName) {this->outFileName = outFileName;};
   void addCmd(CommandLine* singleCmd) {this->singleCmd = singleCmd;};
   std::string getOutFileName() {return outFileName;};
   std::string getInFileName() {return inFileName;};
   int getDepth() {return depth;};
   int setDepth(int depth) {this->depth = depth;};
};

#endif
