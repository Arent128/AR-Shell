#include "InputParser.cpp"
#include "Executable.h"
#include "dAmpersand.h"
#include "dPipe.h"
#include "SemiColon.h"
#include <iostream>
int main(int argc, char** argv)
{
   InputParser* testParse = new InputParser();
   std::string str;
   std::cout << "Please enter some text" << std::endl;
   std::getline(std::cin,str);
   std::vector<std::string>* result = testParse->parse(str);
   std::vector<Connector*> commandLine;
   std::vector<CommandLine*> finalList;
   std::vector<std::string> argList;
   std::vector<std::string>::iterator args = result->begin();
   std::vector<std::string>::iterator cmdList;
   std::string tmp;
   std::cout << std::endl;

   /*Spliiting based of the tokens into their appropriate executable arguments*/
   for (int i = 0; i < result->size(); i++)
   {
      if (result->at(i) == ";" || result->at(i) == "\0" || result->at(i) == "&&" || result->at(i) == "||")
      {
         std::cout << tmp << std::endl;
         argList.push_back(tmp);
            if (*args == ";")
            {
               commandLine.push_back(new SemiColon());
            }
            if (*args == "&&")
            {
               commandLine.push_back(new dAmpersand());
            }
            if (*args == "||")
            {
               commandLine.push_back(new dPipe());
            }

            args++;
            tmp = "";

      }
      else
      {
         tmp += *args + " ";
         args++;
      }
		
   }

   std::cout << std::endl;
      for (int i = 0; i < commandLine.size(); i++)
      {
         if(finalList.size() == 0)
         {
            commandLine[i]->addLeftCmd(new Executable(argList[i]));
            commandLine[i]->addRightCmd(new Executable(argList[i+1]));
            finalList.push_back(commandLine[i]);	
         }
         else
         {
         commandLine[i]->addLeftCmd(commandLine[i - 1]);
         commandLine[i]->addRightCmd(new Executable(argList[i + 1]));
         finalList.push_back(commandLine[i]);
         }
      }
      for (int i = 0; i < finalList.size(); i++)
      {
         std::cout << finalList[i] << std::endl;
      }

      std::cout << finalList.back()->execute() << std::endl;
      std::cout << "Parsing Complete" << std::endl;
   
   return 0;
}
