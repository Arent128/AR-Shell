#include "TestFunc.h"
#include <iostream>

int TestFunc::createArgs()
{
    if(numberOfArgs > 2)
    {
       return -1;
    }
    else
    {
       for(int i = 0; i < input.size(); i++)
       {
	  if(input[i] == 'e' && input[i-1] == '-')
	  {
             flag = 1;
	  }
	  else if(input[i] == 'f' && input[i-1] == '-')
          {
             flag = 2;
	  }
	  else if(input[i] == 'd' && input[i-1] == '-')
	  {
             flag = 3;
	  }
	  if(input[i] == ' ')
	  {
             arg = tmp;
	     tmp = "";
	  }
	  else
	  {
             tmp+= input[i];
	  }
       }
       return 0;
    }
}

bool TestFunc::execute(int fDescripIn, int fDescripOut)
{
    struct stat buf;
    if(createArgs() == -1)
    {
	    std::cout << "Error! The number of arguments for the test command has execeeded 2" << std::endl;
	    return false;
    }
    switch(flag)
    {
	case 1:
	   if(stat(arg.c_str(), &buf) == 0)
	   {
	      std::cout << "True" << std::endl;
              return true;
	   }
	   else
              std::cout << "False" << std::endl;
	      return false;   
	   break;
	case 2:
	   stat(arg.c_str(), &buf);
	   if(S_ISREG(buf.st_mode))
	   {
	      std::cout << "True" << std::endl;
	      return true;
	   }
	   else
              std::cout << "False" << std::endl;
	      return false;
	   break;
	case 3: 
	   stat(arg.c_str(), &buf);
	   if(S_ISDIR(buf.st_mode))
	   {
	      std::cout << "True" << std::endl;
	      return true;
	   }
	   else
              std::cout << "False" << std::endl;
	      return false;
	   break;
	default:
	   if(stat(arg.c_str(), &buf) == 0)
	   {
	      std::cout << "True" << std::endl;
              return true;
	   }
	   else
              std::cout << "False" << std::endl;
	      return false;   
    }
}
    

