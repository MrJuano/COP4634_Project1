#include "parse.hpp"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#define MAXARGS 32


void printInput(char input[500]){
	Param *par = new Param(input);
	par->printParams();
}

void Driver(int integer){
	int status; 
	int debugMode = integer;
	char input[500];
	char inputBuffer[500];


	while(true){
		std::cout << "$$$ ";
		std::cin.getline(input, 500);

		if (strcmp(input, "exit") == 0){
			//wait(NULL);
			wait(&status);
			break;	
		}
		
		if(strcmp(input, "printParam()") == 0)
			printInput(inputBuffer);
		else if(debugMode == 1)
			printInput(input);

		if(strcmp(input, "-Debug") == 0)
			debugMode = 1;
		else
			strcpy(inputBuffer, input);
		
		char *inputRedirect = NULL; 		/* file name or NULL */
		char *outputRedirect = NULL; 		/* file name or NULL */
		int background = 0;			/* either 0 (false) or 1 (true) */
		int argumentCount = 0; 		/* number of tokens in argument vector */
		char *argumentVector[MAXARGS];
		
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

		
		char *args[10];
		int run = 1;

	    		if(argumentVector[0] == NULL){}	
		else if(strcmp(argumentVector[0], "ls") == 0){
			char temp[] = "/bin/ls"; 
			args[0] = temp;
		}
		
		else if(strcmp(argumentVector[0], "grep") == 0){
			char temp[] = "/bin/grep";
			args[0] = temp;  
		}
		else if(strcmp(argumentVector[0], "cat") == 0){
			char temp[] = "/bin/cat";
			args[0] = temp;
		}
		else if(argumentVector[0][0] == '.' && argumentVector[0][1] == '/'){
			args[0] = argumentVector[0];
		}
		else if(strcmp(argumentVector[0], "echo") == 0){
			run = 2;
			char temp[] = "/bin/echo";
			args[0] = temp;

			int i = 1;

			for(; i < argumentCount; ++i){
				args[i] = argumentVector[i];
			}

			args[i + 1] = NULL;
			if(outputRedirect != NULL){
				if(fork() == 0){
					freopen(outputRedirect, "w", stdout);
					execv(args[0], args);
				}
				else
					wait(&status);
			}
			else {
			if(fork() == 0)
				execv(args[0], args);
			else
				wait(&status);
			}
		}
		else{
			run = 0;
		}


		if(run == 1){
			int i = 1;

			if(inputRedirect != NULL){
				args[i] = inputRedirect;
			}

			for(; i < argumentCount; ++i){
				args[i] = (char *)malloc(strlen(argumentVector[i]) + 1);
				strcpy(args[i], argumentVector[i]);
			}
			
			if(inputRedirect == NULL && outputRedirect == NULL)
				args[i] = NULL;
			else
				args[i + 1] = NULL;

			if(outputRedirect != NULL){
				if(fork() == 0){
					freopen(outputRedirect, "w", stdout);
					execv(args[0], args);
				}
				else
					wait(&status);
			}
			else if(background == 0){
				if(fork() == 0)
						execv(args[0], args);
				else
					wait(&status);
			}
			else if(background == 1){
				if(fork() == 0)
						execv(args[0], args);
			}
		}
		else if(run == 2){}
		else{
			std::cout << "ERROR: " << argumentVector[0] << " is not a valid command.\n"; 
		}
	}
}

int main(int args, char* command[]){
	int debugMode = 0;
	
	if(command[1] != nullptr){
		if(strcmp(command[1], "-Debug") == 0){
			debugMode = 1;
		}
	}

	Driver(debugMode);
	
	return 0;
}
