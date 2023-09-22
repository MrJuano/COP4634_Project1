#include "parse.hpp"

void printInput(char input[500]){
	Param *par = new Param(input);
	par->printParams();
}

void ls(char* commands){
	
}

void grep(){

}

void cat(){

}

int main(int args, char* command[]){
	int debugMode = 0;
	
	if(command[1] != nullptr){
		if(strcmp(command[1], "-Debug") == 0)
			debugMode = 1;
	}
	
	char input[1500];
	char inputBuffer[1500];

	while(true){
		std::cout << "$$$ ";
		std::cin.getline(input, 1500);

		if (strcmp(input, "exit") == 0)
			break;		
		if(strcmp(input, "printParam()") == 0)
			printInput(inputBuffer);
		else if(debugMode == 1)
			printInput(input);
		
		if(strcmp(input, "-Debug") == 0)
			debugMode = 1;
		else
			strcpy(inputBuffer, input);
	
	
		char *commands = strtok(const_cast<char *>(input), " \n\t");

		if(strcmp(commands, "ls")){
			commands = strtok(NULL, " \n\t");	
			ls(commands);
		}

		if(strcmp(commands, "grep")){
			commands = strtok(NULL, " \n\t");
			grep();
		}
		if(strcmp(commands, "cat")){
			commands = strtok(NULL, " \n\t");
			cat();
		}
		if(commands[0] == '.' && commands[1] == '/'){

		}

	}

	return 0;
}
