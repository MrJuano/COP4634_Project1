#ifndef PARSE_HPP
#define PARSE_HPP

#define MAXARGS 32

#include <iostream>
#include <cstring>

class Param{
	private:
		char *inputRedirect; 		/* file name or NULL */
		char *outputRedirect; 		/* file name or NULL */
		int background = 0;			/* either 0 (false) or 1 (true) */
		int argumentCount; 		/* number of tokens in argument vector */
		char *argumentVector[MAXARGS]; 	/* array of strings */

	public:
		Param(const char*);
		~Param();
		void printParams();
};

#endif
