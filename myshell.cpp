#include "parse.hpp"

int main(){
	Param *par = NULL;
	int debugMode = 0;

	while(true){
		char input[500];
		std::cout << "$$$ ";
		std::cin.getline(input, 1500);
		par = new Param(input);

		if (strcmp(input, "exit") == 0){
			break;		
		}

		if(debugMode == 1)
			par->printParams();

		if(strcmp(input, "-Debug") == 0)
			debugMode = 1;
	}

	return 0;
}
