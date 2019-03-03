#ifndef DPIPE_H
#define DPIPE_H
#include "Connector.h"

class dPipe : public Connector 
{
   //Constructor and inheritance
   public:
   /*Constructors and Deconstructors*/
   dPipe() : Connector() 
   {

   };

   ~dPipe()
   {
   
   };

   //Assigning and inheriting left and right cmd children
   dPipe(CommandLine* lhs, CommandLine* rhs) : Connector(lhs, rhs) 
   {

   };
   dPipe(int depth) : Connector(depth) {};

   void addLeftCmd(CommandLine* lhs) 
   {
       Connector::lhs = lhs;
   };

   void addRightCmd(CommandLine* rhs)
   {
       Connector::rhs = rhs;
   };

   /*Inherited virtual functions from CommandLine*/
   //function declaration for execute()
   bool execute(int fDescripIn, int FdDscripOut);

};

#endif
