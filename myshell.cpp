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
	
	if(commands == NULL){
		char *args[] = {"/bin/ls", NULL};	
		if(fork() == 0)
			execv(args[0], args);
		else
			wait(&status);
	}
	else if(strcmp(commands, "-l") == 0){
		commands = strtok(NULL, " \n\t-l");
		if(commands == NULL){
			char *args[] = {"/bin/ls", "-l", NULL};
			if(fork() == 0)
				execv(args[0], args);
			else
				wait(&status);
		}
		else if(commands[0] == '>'){
			char *fileName = new char[strlen(commands) + 1];
			strcpy(fileName, commands);
			fileName++;

			char *args[] = {"/bin/ls", "-l", fileName, NULL};
			if(fork() == 0){
				freopen(fileName, "w", stdout);
               			execlp("ls", "ls", "-l", (char *)NULL);
			}
			else
				wait(&status);

		}
		else{
			std::cout << "ERROR\n";
		}
	
	}	
}

void grep(char *commands){
	if(commands == NULL){std::cout << "FUCG";}
	else if(commands[0] == '-' && commands[1] == 'i'){
		commands = strtok(NULL, " \t\n");

		if(commands == NULL){}
		else if(strcmp(commands, "shell") == 0){
			commands = strtok(NULL, " \t\n");

			if(commands == NULL){}
			else {
				char *args[] = {"grep", "-i", "shell", commands, NULL};
				execv("/bin/grep", args);
			}
		}
	}
}

void cat(char *commands){
	int status;
	if(commands == NULL){std::cout << "ERROR: ENTER FILE NAME\n";}
	else if(commands[0] == '<'){
		char *fileName = new char[strlen(commands) + 1];
		strcpy(fileName, commands);
		fileName++;
		
		commands = strtok(NULL, " \t\n");

		if(commands == NULL){
			char *args[] = {"cat", fileName, NULL};
			if(fork() == 0){
				execvp("cat", args);
			}
			else
				wait(&status);
		}
		else {
			if(strcmp(commands, "&") == 0){
				char *args[] = {"cat", fileName, NULL};
				if(fork() == 0){
					execvp("cat", args);
				}
				else
					wait(NULL);
			}
			else
				std::cout << "ERROR: UNEXPECTED INPUT\n";
		}

	}
	else{
		char *fileName = new char[strlen(commands)];
		strcpy(fileName, commands);
		
		commands = strtok(NULL, " \t\n");	

		if(commands == NULL){
			char *args[] = {"cat", fileName, NULL};
			if(fork() == 0){
				execvp("cat", args);
			}
			else
				wait(&status);
		}
		else {
			if(strcmp(commands, "&") == 0){
				char *args[] = {"cat", fileName, NULL};
				if(fork() == 0){
					execvp("cat", args);
				}
				else
					wait(NULL);
			}
			else
				std::cout << "ERROR: UNEXPECTED INPUT\n";
		}
	}
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
		
		if(commands == NULL){}	
		else if(strcmp(commands, "ls") == 0){
			commands = strtok(NULL, " \n\t");	
			ls(commands);
		}
		else if(strcmp(commands, "grep") == 0){
			commands = strtok(NULL, " \n\t");
			grep(commands);
		}
		else if(strcmp(commands, "cat") == 0){
			commands = strtok(NULL, " \n\t");
			cat(commands);
		}
		else if(commands[0] == '.' && commands[1] == '/'){

		}
	}

	return 0;
}
