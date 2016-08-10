#include "read.h"
#include "commands.h"
#include <stdio.h>
#include <string.h>

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

				if (strcmp(token,"push")==0) { 
								*command = PUSH;
								readNumber(file, argument);
				} else if (strcmp(token, "pop")==0) {
								*command = POP;
				} else if (strcmp(token, "add")==0) {
								*command = ADD;
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
