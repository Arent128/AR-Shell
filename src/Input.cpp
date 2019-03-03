#include "Input.h"

//uses parser function by checking connector 
int Input::cmdCheck()
{
   return shellParser->connectorCheck(userInput);
}

//the commandline sudo 
void Input::initShell()
{
    std::cout << "$";
    std::getline(std::cin, userInput); 
}

//single args
void Input::singleCmd()
{
      int x = 0;
      args = result->begin();
      std::string testString = *args;
      for (args; args != result->end(); args++)
      {
	 if(*args == "test" || *args == "]")
	 {
             
	 }
	 else
         {  
            tmp += *args + " ";
            x++;
	 }
      }
      if(testString == "test")
      {
         commandLine.push_back(new TestFunc(tmp, x));
	 argList.push_back(commandLine.back());
	 commandLine.pop_back();
      }
      else
      {
         commandLine.push_back(new Executable(tmp, x));
	 argList.push_back(commandLine.back());
	 commandLine.pop_back();
      }      
}


void Input::createTree()
{
   int x = 0;
   args = result->begin();
   int depth = 0;
   std::string testString = "";
   std::string inFileName = "";
   for (int i = 0; i < result->size(); i++)
   {
   //will recognized whether which connector will be used
      if (result->at(i) == ";" || result->at(i) == "\0" || result->at(i) == "&&" || result->at(i) == "||"  || result->at(i) == "(" || result->at(i) == ")" || result->at(i) == "]" || result->at(i) == "test" || result->at(i) == ">" || result->at(i) == ">>" || result->at(i) == "<" || result->at(i) == "|")
      {
        if(*args == "test")
	    {
	       testString = *args;
	    }

	    if(*args == "]")
	    {
	       argList.push_back(new TestFunc(tmp, x));
	       testString = "";
	    }

	    if (tmp != "")
	    { 
	       if(testString == "test")
	       {
	          argList.push_back(new TestFunc(tmp, x));
              testString = "";
	       }
	       else
	       {
                  argList.push_back(new Executable(tmp, x));
	       }
	    }

        if (*args == "(")
        {
            depth++;
            connectors.push_back(new Parenthesis());
        }

        if (*args == ")")
        {
            if(tmp == "" && (int)(argList.size()) == 0)
            {
	            std::cout << "Error a set of parenthesis has no arguements" << std::endl;
                break;
            }
            else
            { 
                if(connectors.back()->getDepth() < 0 )
                {

                  tmp.pop_back();
                  connectors.back()->addOutFile(tmp.c_str());
                  argList.pop_back();
                  connectors.back()->addCmd(argList.back());
                  argList.pop_back();
                  argList.push_back(connectors.back());
                  connectors.pop_back();
                }
                else
                {
                  depth--;
                  connectors.back()->addRightCmd(argList.back());
                  argList.pop_back();
                  connectors.back()->addLeftCmd(argList.back());
                  argList.pop_back();
                  argList.push_back(connectors.back());
                  connectors.pop_back();
                  connectors.back()->addCmd(argList.back());
                  argList.pop_back();
                  argList.push_back(connectors.back());
                  connectors.pop_back();
                }
            }
        }
        if(*args == ">")
        {
            if(connectors.size() > 0)
            {
                if(connectors.back()->getDepth() == -2)
                {
                    inFileName = tmp;
                    tmp.pop_back();
                    connectors.back()->addOutFile(tmp.c_str());
                    argList.pop_back();
                    connectors.back()->addCmd(argList.back());
                    argList.pop_back();
                    argList.push_back(connectors.back());
                    connectors.pop_back();

                }
            }
            connectors.push_back(new OutputDirec(-2));
        }
        if(*args == ">>")
        {
            if(connectors.size() > 0)
            {
                if(connectors.back()->getDepth() == -2)
                {
                    inFileName = tmp;
                    tmp.pop_back();
                    connectors.back()->addOutFile(tmp.c_str());
                    argList.pop_back();
                    connectors.back()->addCmd(argList.back());
                    argList.pop_back();
                    argList.push_back(connectors.back());
                    connectors.pop_back();
                }
            }
            connectors.push_back(new OutputAppend(-2));
        }

        if(*args == "<")
        {
            if(connectors.size() > 0)
            {
                if(connectors.back()->getDepth() == -2)
                {
                    inFileName = tmp;
                    tmp.pop_back();
                    connectors.back()->addOutFile(tmp.c_str());
                    argList.pop_back();
                    connectors.back()->addCmd(argList.back());
                    argList.pop_back();
                    argList.push_back(connectors.back());
                    connectors.pop_back();

                }
            }
            connectors.push_back(new InputDirec(-2));
        }
        if(*args == "|")
        {
            if(connectors.size() != 0)
            {
                if(connectors.back()->getDepth() == -2)
                {
                    tmp.pop_back();
                    connectors.back()->addOutFile(tmp.c_str());
                    argList.pop_back();
                    connectors.back()->addCmd(argList.back());
                    argList.pop_back();
                    argList.push_back(connectors.back());
                    connectors.pop_back();
                }
            }
            if(connectors.size() != 0)
            {
                connectors.back()->addRightCmd(argList.back());
                argList.pop_back();
                connectors.back()->addLeftCmd(argList.back());
                argList.pop_back();
                argList.push_back(connectors.back());
                connectors.pop_back();
            }
            connectors.push_back(new Pipe(-3));
        }
	    if (*args == "\0")
	    {
            if(connectors.back()->getDepth() == -2)
            {
                  if(inFileName != "")
                  {
                    connectors.back()->addInFile(inFileName.c_str());
                  }
                  tmp.pop_back();
                  connectors.back()->addOutFile(tmp.c_str());
                  argList.pop_back();
                  connectors.back()->addCmd(argList.back());
                  argList.pop_back();
                  argList.push_back(connectors.back());
                  connectors.pop_back();

            }
            if((int)connectors.size() != 0)
            {
                connectors.back()->addRightCmd(argList.back());
                argList.pop_back();
                connectors.back()->addLeftCmd(argList.back());
                argList.pop_back();
                argList.push_back(connectors.back());
                connectors.pop_back();
	        }		
	    }

	    else if ((int)connectors.size() != 0 && connectors.back()->getDepth() == depth)
	    {
            connectors.back()->addRightCmd(argList.back());
            argList.pop_back();
            connectors.back()->addLeftCmd(argList.back());
            argList.pop_back();
            argList.push_back(connectors.back());
            connectors.pop_back();
	    }

            if (*args == ";")
            {
               
            if(connectors.size() > 0)
            {
                if(connectors.back()->getDepth() == -2)
                {
                    inFileName = tmp;
                    tmp.pop_back();
                    connectors.back()->addOutFile(tmp.c_str());
                    argList.pop_back();
                    connectors.back()->addCmd(argList.back());
                    argList.pop_back();
                    argList.push_back(connectors.back());
                    connectors.pop_back();
                }
            }
               connectors.push_back(new SemiColon(depth));
            }

            if (*args == "&&")
            {
               
            if(connectors.size() > 0)
            {
                if(connectors.back()->getDepth() == -2)
                {
                    inFileName = tmp;
                    tmp.pop_back();
                    connectors.back()->addOutFile(tmp.c_str());
                    argList.pop_back();
                    connectors.back()->addCmd(argList.back());
                    argList.pop_back();
                    argList.push_back(connectors.back());
                    connectors.pop_back();
                }
            }
               connectors.push_back(new dAmpersand(depth));
            }

            if (*args == "||")
            {

            if(connectors.size() > 0)
            {
                if(connectors.back()->getDepth() == -2)
                {
                    inFileName = tmp;
                    tmp.pop_back();
                    connectors.back()->addOutFile(tmp.c_str());
                    argList.pop_back();
                    connectors.back()->addCmd(argList.back());
                    argList.pop_back();
                    argList.push_back(connectors.back());
                    connectors.pop_back();
                }
            }
               connectors.push_back(new dPipe(depth));
            }
               args++;
               tmp = "";
               x = 0;
      }

      else
      {
         tmp += *args + " ";
         args++;
         x++;
      }
   }
}
