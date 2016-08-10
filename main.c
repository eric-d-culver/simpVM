#include "list.h"
#include "stack.h"
#include "read.h"
#include "execute.h"
#include "commands.h"
#include "runtime.h"
#include <stdlib.h>
#include <stdio.h>

#define MAX_LINES 256

int main(int argc, char** argv) {
				runTime* rt;
				int command = 0;
				int argument = 0;

				rt = malloc(sizeof(runTime) + MAX_LINES * sizeof(long int));
				rt->stack = NULL;


				if (argc > 1) {
								rt->inFile = fopen(argv[1], "r");
				} else { 
								rt->inFile = stdin;
				}

				readLineNumbers(rt->inFile, rt->lineNumbers, MAX_LINES);

				while (!feof(rt->inFile)) {
								readCommand(rt->inFile, &command, &argument);
								/* printf("%d %d\n", command, argument); */
								executeCommand(rt, command, argument);
				}

				if (rt->inFile != stdin) {
								fclose(rt->inFile);
				}

				free(rt);

				return 0;
}
