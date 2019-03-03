#include "Pipe.h"
#include <iostream>
bool Pipe::execute(int fDescripIn, int fDescripOut)
{
   int fileDescrip[2];
   pipe(fileDescrip);
   if(!lhs->execute(fDescripIn, fileDescrip[1]))
       return false;
   close(fileDescrip[1]);
   if(!rhs->execute(fileDescrip[0], fDescripOut))
       return false;
   close(fileDescrip[0]);
   return true;
}
