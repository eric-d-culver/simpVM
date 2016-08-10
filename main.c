#include "list.h"
#include "stack.h"
#include "read.h"
#include "commands.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINES 256

int main(int argc, char** argv) {
				long int linenums[MAX_LINES];
				node* stack = NULL;
				int command = 0;
				int argument = 0;
				FILE * inFile;


				if (argc > 1) {
								inFile = fopen(argv[1], "r");
				} else { 
								inFile = stdin;
				}

				readLineNumbers(inFile, linenums, MAX_LINES);

				while (!feof(inFile)) {
								readCommand(inFile, &command, &argument);
								/* executeCommand(inFile, stack, command, argument); */
				}

				if (inFile != stdin) {
								fclose(inFile);
				}

				return 0;
}
