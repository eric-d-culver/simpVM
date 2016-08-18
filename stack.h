#ifndef STACK_H
#define STACK_H
#include "list.h"

void push(node** stack, int data);

int pop(node** stack);

int peek(node** stack);

void extract(node** stack, int depth);

void freeStack(node** stack);

void stackTest(node* stack);

#endif
