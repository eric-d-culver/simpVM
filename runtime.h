#ifndef RUNTIME_H
#define RUNTIME_H
#include "list.h"
#include <stdio.h>

typedef struct _runTime {
				FILE* inFile;
				node* stack;
				long int lineNumbers[];
} runTime;
 #endif
