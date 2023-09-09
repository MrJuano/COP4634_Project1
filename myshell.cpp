#include "parse.hpp"

int main(){
	int end = 0;
	while(end == 0){
		end = driver();
	}

	return 1;
}

int driver(){
	std::cout << "$$$ ";
	std.cin.getline(input);

	if (strcmp(input, "exit") == 0){
		return 1;		
	}

	Param par = new Param(input);
	
	par.printParams();
}
