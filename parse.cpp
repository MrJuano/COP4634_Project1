#include "parse.hpp"

Parse::Parse(string input){
	std::istringstream stream(input);
    	std::string normalInput;
    	std::string command;

    	while (stream >> command){
		if(command[0] == "<")
			inputRedirect = strtok(command, " <\t";
		else if (command[0] == ">")
			outputReditrct = strtok(command, " >\t";
		else if (command[0] == "&")
			background = 1;
		else
			normalInput += command + " ";
	}

	argumentCount = argumentVector.size();
	
}

void Parse::printParams(){
}
