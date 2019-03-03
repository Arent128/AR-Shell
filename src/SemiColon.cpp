#include "SemiColon.h"


bool SemiColon::execute(int fDescripIn, int fDescripOut)
{
	lhs->execute(fDescripIn, fDescripOut);

	if (rhs->execute(fDescripIn, fDescripOut))
	  return true;
	  return false;
}


