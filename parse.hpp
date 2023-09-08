#ifndef PARAM_HPP
#define PARAM_HPP

class Param{
	private:
		char *inputRedirect; 		/* file name or NULL */
		char *outputRedirect; 		/* file name or NULL */
		int background;			/* either 0 (false) or 1 (true) */
		int argumentCount; 		/* number of tokens in argument vector */
		char *argumentVector[MAXARGS]; 	/* array of strings */

	public:
		void printParams();
}

#endif
