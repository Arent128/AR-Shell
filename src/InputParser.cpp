#include "InputParser.h"

//input that allows parsing
std::vector<std::string>* InputParser::parse(std::string input)
{
      std::vector<std::string>* tokenVector = new std::vector<std::string>();
      int parseStrategy = connectorCheck(input);  
      //will be checking if connector is in
      if (parseStrategy == 2)
      {
            for (int i = 0; i < input.length(); i++)
            {
	       if(input[i] == '[' && input[i+1] != ' ')
		  input.insert(i+1," ");
	       if(input[i] == ']' && input[i-1] != ' ')
		  input.insert(i," ");
           if(input[i] == '(' && input[i-1] != ' ')
             input.insert(i, " ");
           if(input[i] == '(' && input[i+1] != ' ')
             input.insert(i+1, " ");
           if(input[i] == ')' && input[i-1] != ' ')
             input.insert(i, " ");
           if(input[i] == ')' && input[i+1] != ' ')
             input.insert(i+1, " ");
            }
           char* str = new char[input.length()+1];
           std::strcpy(str, input.c_str());
           char* tokens;
           std::string tmp = "[";
           std::string paren2 = ")";
           tokens = std::strtok(str, " (");
           while (tokens != NULL)
           {
	      if(tokens == tmp)
	      {
		   tokens = (char*)"test";
	      }
              if(tokens != paren2)
                tokenVector->push_back(tokens);
              tokens = std::strtok(NULL, " ");
           }
           delete[] str;
        }
	else if (parseStrategy == 3)
	{ 
            for (int i = 0; i < input.length(); i++)
            {
               if (input[i] == ';' && input[i-1] != ' ')
                  input.insert(i," ");
	       if(input[i] == '(' && input[i-1] != ' ')
		  input.insert(i," ");
	       if(input[i] == '(' && input[i+1] != ' ')
		  input.insert(i+1, " ");
	       if(input[i] == ')' && input[i-1] != ' ')
		  input.insert(i," ");
	       if(input[i] == ')' && input[i+1] != ' ')
		  input.insert(i+1, " ");
	       if(input[i] == '[' && input[i+1] != ' ')
		  input.insert(i+1," ");
	       if(input[i] == ']' && input[i-1] != ' ')
		  input.insert(i," ");   
            }
            char* str = new char[input.length()+1];
            std::strcpy(str,input.c_str());
            char* tokens;
            tokens = std::strtok(str, " ");
               while (tokens != NULL)
               {
		  std::string tmp = "[";
		  if(tokens == tmp)
		  {
		      tokens = (char*)"test";
		  }
                  tokenVector->push_back(tokens);
                  tokens = std::strtok(NULL, " ");
               }
		tokenVector->push_back("\0");
		delete[] str;
	}
          return tokenVector;
}

//will be checking if ampersand or pipe in
int InputParser::connectorCheck(std::string &input)
{
   bool connector = false;
   bool commentChar = false;
   bool outputDirec = false;
   bool spaceInput = false;
   int leftBracket = 0;
   int rightBracket = 0;
   int leftParen = 0;
   int rightParen = 0;
   int commentIndex;
      for (int i = 0; i < input.size(); i++)
      {
        if (input[i] == '&' || input[i] == '|' || input[i] == ';')
        {
            connector = true;
        }

        if (input [i] == '#')
        {
            commentChar = true;
            commentIndex = i;
        }
        if (input [i] == '(')
        {
            leftParen++;
        }

        if (input [i] == ')')
        {
            rightParen++;
        }

        if (input[i] == '[')
        {
            leftBracket++;  
        }

        if (input[i] == ']')
        {
            rightBracket++;
        }
        if (input[i] == '>' || input[i] == '<')
        {
            outputDirec = true;
        }
     }
     if (leftBracket != rightBracket)
     {
          return -2;
     }
     else if(leftBracket == rightBracket && leftBracket != 0 && connector == true)
     {
          return 3;
     }
     if (commentChar)
     {
          input.erase(commentIndex,input.length());
     }
     if(outputDirec)
     {
          return 3;
     }
     if (leftParen != rightParen)
     {
          return -1;
     }
     else if(leftParen == rightParen && leftParen != 0)
     {
          if(!connector)
            return 2;
          return 3;
     }
     else
     {
       if (connector)
       {
          return 3;
       }
       else
         return 2;
     }
}
