#include "read.h"
#include "commands.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void readToken(FILE* file, char* token) {
				fscanf(file, "%s", token);
				return;
}

void readNumber(FILE* file, int* num) {
				fscanf(file, "%d", num);
				return;
}

void readLine(FILE* file, char* line) {
				fgets(line, 255, file);
				return;
}

void readLineNumbers(FILE* file, long int* linenums, int size) {
				char line[255];

				int i=0;
				do {
								linenums[i] = ftell(file);
								i++;
				} while(i<size && fgets(line, 255, file)!=NULL);

				rewind(file);

				return;
}

void readCommand(FILE* file, int* command, int* argument) {
				char token[255];

				readToken(file, token);
				
				for (int i=0; token[i]; i++) {
								token[i] = tolower(token[i]);
				}

				if (feof(file)) {
								*command = ENDOFFILE;
				} else if (strcmp(token,"push")==0) { 
								*command = PUSH;
								readNumber(file, argument);
				} else if (strcmp(token, "pop")==0) {
								*command = POP;
				} else if (strcmp(token, "add")==0) {
								*command = ADD;
				} else if (strcmp(token, "sub")==0) {
								*command = SUB;
				} else if (strcmp(token, "mul")==0) {
								*command = MUL;
				} else if (strcmp(token, "div")==0) {
								*command = DIV;
				} else if (strcmp(token, "mod")==0) {
								*command = MOD;
				} else if (strcmp(token, "ifeq")==0) {
								*command = IFEQ;
								readNumber(file, argument);
				} else if (strcmp(token, "jump")==0) {
								*command = JUMP;
								readNumber(file, argument);
				} else if (strcmp(token, "print")==0) {
								*command = PRINT;
				} else if (strcmp(token, "dup")==0) {
								*command = DUP;
				} else if (strcmp(token, "extract")==0) {
								*command = EXTR;
								readNumber(file, argument);
				} else {
								*command = ERROR;
				}

				return;
}

void readTest(FILE* inFile) {
				int num;
				char str[255];
				readToken(inFile, str);
				printf("%s\n", str);
				readNumber(inFile, &num);
				printf("%d\n", num);
				
				rewind(inFile);
				readLine(inFile, str);
				printf("%s", str);

				return;
}
