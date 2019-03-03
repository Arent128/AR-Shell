#include "dAmpersand.h"

//Ampersand connector
//bool on whether to execute left side of child and/or right side of the child
bool dAmpersand::execute(int fDescripIn, int fDescripOut) 
{
   if (lhs->execute(fDescripIn, fDescripOut) && rhs->execute(fDescripIn, fDescripOut))
      return true;

      //executing if both of them are executed
      return false;
}

