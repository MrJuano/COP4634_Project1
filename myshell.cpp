#include "parse.hpp"

void printInput(char input[500]){
	Param *par = new Param(input);
	par->printParams();
}

void ls(char input[500], char file[500]){
	
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
		std::cin.getline(input, 1500);

		if (strcmp(input, "exit") == 0){
			break;		
		}
		
		if(strcmp(input, "printParam()") == 0){
			printInput(inputBuffer);

		}
		else if(debugMode == 1)
			printInput(input);
		
		if(strcmp(input, "-Debug") == 0)
			debugMode = 1;
		else
			strcpy(inputBuffer, input);
	}

	return 0;
}
