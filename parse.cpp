#include "parse.hpp"

Param::Param(const char *input){
	inputRedirect = NULL;
	outputRedirect = NULL;
	background = 0;
	argumentCount = 0;
	
	char *commands = strtok(const_cast<char *>(input), " \n\t");

	while(commands != nullptr){
		if(commands[0] == '<'){
			if(commands != nullptr){
				inputRedirect = new char[strlen(commands) + 1];
				strcpy(inputRedirect, commands);
				inputRedirect++;
			}
		}
		else if(commands[0] == '>'){
			if(commands != nullptr){
				outputRedirect = new char[strlen(commands) + 1];
				strcpy(outputRedirect, commands);
				outputRedirect++;
			}
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

	delete commands;
}

Param::~Param(){
	delete[] (inputRedirect - 1);
	delete[] (outputRedirect - 1);

	for(int i = 0; i < argumentCount; ++i){
		delete[] argumentVector[i];
	}
}

void Param::printParams(){
	if(inputRedirect == NULL)
		std::cout << "InputRedirect: [NULL]\n";		
	else
		std::cout << "InputRedirect: [" << inputRedirect << "]\n";
	if(outputRedirect == NULL)
		std::cout << "OutputRedirect: [NULL]\n";
	else
		std::cout << "OutputRedirect: [" << outputRedirect << "]\n";

	std::cout << "Background: [" << background << "]\n";
	std::cout << "ArgumentCount: [" << argumentCount << "]\n";
	
	for(int i = 0; i < argumentCount; ++i){
		std::cout << "ArgumentVector[" << i << "]: [" << argumentVector[i] << "]\n"; 
	}

	std::cout << "\n";
}
