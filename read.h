#ifndef READ_H
#define READ_H
#include <stdio.h>

void readLineNumbers(FILE* file, long int* lineNumbers, int size);

void readCommand(FILE* file, int* command, int* argument);

void readTest(FILE* inFile);

#endif
