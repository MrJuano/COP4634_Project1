#include "parse.hpp"

int main(){
	Param *par = NULL;
	while(true){
		char input[500];
		std::cout << "$$$ ";
		std::cin.getline(input, 500);

		if (strcmp(input, "exit") == 0){
			break;		
		}

		par = new Param(input);
	
		par->printParams();
	}

	return 0;
}
