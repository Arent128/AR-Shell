#include "dPipe.h"

//pipe connector
//bool for either or left or right child to execute
bool dPipe::execute(int fDescripIn, int fDescripOut)
{
   if (lhs->execute(fDescripIn, fDescripOut) || rhs->execute(fDescripIn, fDescripOut))
      return true;
      return false;
}

