#ifndef DAMPERSAND_H
#define DAMPERSAND_H
#include "Connector.h"
class dAmpersand : public Connector
{
	public:
	/*Constructors and Deconstructors*/
	dAmpersand() : Connector(){};
	~dAmpersand(){};

	dAmpersand(CommandLine* lhs, CommandLine* rhs) : Connector(lhs, rhs) {};
	dAmpersand(int depth) : Connector(depth) {};
	void addLeftCmd(CommandLine* lhs) {Connector::lhs = lhs;};
	void addRightCmd(CommandLine* rhs) {Connector::rhs = rhs;};

	/*Inherited virtual function from CommandLine*/
	bool execute(int fDescripIn, int fDescripOut);
};

#endif
