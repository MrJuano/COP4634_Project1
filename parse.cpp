#include "parse.hpp"

Parse::Parse(string input){
	inputRedirect = NULL;
	outputRedirect = NULL;
	background = 0;
	argumentCount = argumentVector.size();
	
	char *commands = strtok(input, " \n\t");

	while(commands != nullptr){
		if(strcmp(commands, "<") == 0){
			commands = strtok(NULL, " \n\t");
			//inputRedirect = new char[strlen(commands) + 1];
			strcpy(inputRedirect, commands);
		}
		else if(strcmp(commands, ">") == 0){
			commands = strtok(NULL, " \n\t");
			//outputRedirect = new char[strlen(commands) + 1];
			strcpy(outputRedirect, commands);
		}
		else if(strcmp(commands, "&") == 0)
			background = 1;
		else {
			argumentVector[argumentCount] = new char[strlen(commands) + 1];
			strcpy(argumentVector[argumentCount], commands);
			argumentCount += 1;
		}

		commands = strtok(NULL, " \n\t");
	}

}

Param::~Param(){
	delete[] inputRedirect;
	delete[] outputRedirect;

	for(int i = 0; i < argumentCount; ++i){
		delete[] argumentVector[i];
	}
}

void Parse::printParams(){
	std::cout << "InputRedirect: [" << inputRedirect << "]\n";
	std::cout << "OutputRedirect: [" << outputRedirect << "]\n";
	std::cout << "Background: [" << background << "]\n";
	std::cout << "ArgumentCount: [" << argumentCount << "]\n";
	
	for(int i = 0; i < argumentCount; ++i){
		std::cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]\n"; 
	}

	std::cout << "\n";
}
