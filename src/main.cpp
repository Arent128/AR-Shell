#include "Input.h"

int main(int argv, char** argc)
{
   while(1)
   {
      Input* inputLine = new Input();
      inputLine->initShell();
      inputLine->parse();
      int cmdStrategy = inputLine->cmdCheck();
      if (cmdStrategy == 2)
      {
         inputLine->singleCmd();
         inputLine->execute(0,1);
      }

      else if (cmdStrategy == 3)
      {
	 inputLine->createTree();
	 inputLine->execute(0,1);
      }
      else
      {
        std::cout << "Error: Invaild Input ";
        if(cmdStrategy == -1)
           std::cout << "The number of parenthesis used is uneven" << std::endl;        else
           std::cout << "The number of brackets used is uneven" << std::endl;
      }
   }
   return 0;
}
