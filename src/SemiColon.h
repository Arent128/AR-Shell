#ifndef SEMICOLON_H
#define SEMICOLON_H
#include "Connector.h"
class SemiColon : public Connector
{
   public:
   /*Constructors and Deconstructors*/
   SemiColon() : Connector()
   {

   };

   ~SemiColon()
   {

   };

   SemiColon(CommandLine* lhs, CommandLine* rhs) : Connector(lhs, rhs)
   {
   
   };
   SemiColon(int depth) : Connector(depth) {};
   void addLeftCmd(CommandLine* lhs) 
   {
      Connector::lhs = lhs;
   };

   void addRightCmd(CommandLine* rhs) 
   {
      Connector::rhs = rhs;
   };

   /*Inherited virtual function from CommandLine*/
   bool execute(int fDescripIn, int fDescripOut);

};

#endif
