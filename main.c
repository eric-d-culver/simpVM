#include "list.h"
#include "stack.h"
#include "read.h"
#include "commands.h"
#include <stdio.h>
#include <string.h>

#define MAX_LINES 256

int main(int argc, char** argv) {
				long int linenums[MAX_LINES];
				node* stackHead = NULL;
				FILE * inFile;

				int command = 0;
				int argument = 0;

				if (argc > 1) {
								inFile = fopen(argv[1], "r");
				} else { 
								inFile = stdin;
				}

				/* stackTest(stackHead); */
				/* readTest(inFile); */

				readLineNumbers(inFile, linenums, MAX_LINES);

				readCommand(inFile, &command, &argument);

				printf("%d %d\n", command, argument);

				if (inFile != stdin) {
								fclose(inFile);
				}

				return 0;
}
