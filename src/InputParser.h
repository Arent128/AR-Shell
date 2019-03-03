#ifndef INPUTPARSER_H
#define INPUTPARSER_H

#include <iterator>
#include <regex>
#include <string>
#include <cstring>
#include <vector>
#include <iostream>

class InputParser
{
	public:
	/*Constructor and Deconstructors*/
	InputParser(){};
	~InputParser(){};

	/*public member functions*/
	std::vector<std::string>* parse(std::string input);
	int connectorCheck(std::string &input);
};

#endif
