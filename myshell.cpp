#include "parse.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


void printInput(char input[500]){
	Param *par = new Param(input);
	par->printParams();
}

void ls(char* commands){
	int status;
	
	if ( fork() == 0 )
		execv( "/bin/ls", NULL );
	else
		wait( &status );	
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
	
	char input[500];
	char inputBuffer[500];

	while(true){
		std::cout << "$$$ ";
		std::cin.getline(input, 500);
		
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
		
		if(strcmp(commands, "ls") == 0){
			commands = strtok(NULL, " \n\t");	
			ls(commands);
		}
		else if(strcmp(commands, "grep") == 0){
			commands = strtok(NULL, " \n\t");
			grep();
		}
		else if(strcmp(commands, "cat") == 0){
			commands = strtok(NULL, " \n\t");
			cat();
		}
		else if(commands[0] == '.' && commands[1] == '/'){

		}
	}

	return 0;
}
