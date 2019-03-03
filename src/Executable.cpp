#include "Executable.h" 

void Executable::createArgList(std::string args)
{	   
      int x = 0;
      cArgs = new char*[numberOfArgs+1];
      //Creating the amount of arguments inputted from the user
         for (int i = 0; i < args.length(); i++) 
         {
            if (args[i] == ' ') 
            {
               cArgs[x] = new char[tmp.size()+1];
               strcpy(cArgs[x], tmp.c_str());
               tmp ="";
               x++;
            }
            else 
            {
               tmp += args[i];
            }
         }
   cArgs[numberOfArgs] = NULL;
}

bool Executable::execute(int fDescripIn, int fDescripOut) 
{
   //creating bool function if forked
   int statusValue;
   createArgList(args);
   std::string exitString = cArgs[0];
   if(exitString.compare("exit") == 0)
   {
      exit(1);
   }
   pid_t pid = fork();

   if (pid == -1) 
   {
      perror("fork");
      return false;
   }
   else if (pid == 0) 
   {
   //funciton if execvp did not work properly
   //std::cout << "Child: " << pid << std::endl;
      if(dup2(fDescripIn,0) == -1)
      {
          perror("dup2");
          return false;
      }
      if(dup2(fDescripOut,1) == -1)
      {
          perror("dup2");
          return false;
      }
      if (execvp(cArgs[0], cArgs) == -1) 
      {
          perror("execvp did not run properly");
	  exit(42);
      }	
   }
   if (pid > 0) 
   {
   //Adding funciton that will hold the funciton and let user know if wait, then false
   //std::cout << "Parent: " << pid << std::endl;
      if (waitpid(pid,&statusValue,WUNTRACED) == -1) 
      {
          perror("wait");
      }
   }
   if(WEXITSTATUS(statusValue) > 0)
	   return false;
   return true; 
}
