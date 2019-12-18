#ifndef INPUT_H
#define INPUT_H

#include "CommandLine.h"
#include "SemiColon.h"
#include "dAmpersand.h"
#include "Parenthesis.h"
#include "dPipe.h"
#include "InputParser.h"
#include "Executable.h"
#include "TestFunc.h"
#include "OutputDirec.h"
#include "OutputAppend.h"
#include "InputDirec.h"
#include "Pipe.h"
#include <limits.h>

class Input : public CommandLine
{
   protected:
      std::vector<std::string>* result;
      std::vector<Connector*> connectors;
      std::vector<CommandLine*> argList;
      std::vector<CommandLine*> commandLine;
      std::vector<std::string>::iterator args;
      std::string userInput;
      std::string tmp;
      InputParser* shellParser = new InputParser();
   public:
      /*Constructors and Deconstructors*/
      Input() 
      {

      };

      Input(std::string userInput)
      {
         this->userInput = userInput;
      };

      ~Input()
      {

      };

      /*Public Member Functions*/
      void initShell();
      int cmdCheck();
      void singleCmd();
      void parse()
      {
         this->result = shellParser->parse(userInput);
      };
      void createTree();

      /*Inherited Virtual Methods*/
      bool execute(int fDesrcripIn, int FDescripOut)
      {
         return argList.back()->execute(0,1);
      };	
};

#endif
