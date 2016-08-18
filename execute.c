#include "execute.h"
#include "stack.h"
#include "commands.h"
#include <stdio.h>

void executeCommand(runTime* rt, int command, int argument) {
				int temp;
				switch(command) {
								case POP:
												pop(&(rt->stack));
												break;
								case PUSH:
												push(&(rt->stack), argument);
												break;
								case ADD:
												temp = pop(&(rt->stack))+pop(&(rt->stack));
												push(&(rt->stack), temp);
												break;
								case SUB:
												temp = pop(&(rt->stack))-pop(&(rt->stack));
												push(&(rt->stack), temp);
												break;
								case MUL:
												temp = pop(&(rt->stack))*pop(&(rt->stack));
												push(&(rt->stack), temp);
												break;
								case DIV:
												temp = pop(&(rt->stack))/pop(&(rt->stack));
												push(&(rt->stack), temp);
												break;
								case MOD:
												temp = pop(&(rt->stack))%pop(&(rt->stack));
												push(&(rt->stack), temp);
												break;
								case IFEQ:
												if(pop(&(rt->stack))==0) 
																fseek(rt->inFile,rt->lineNumbers[argument],SEEK_SET);
												break;
								case JUMP:
												fseek(rt->inFile,rt->lineNumbers[argument],SEEK_SET);
												break;
								case PRINT:
												temp = pop(&(rt->stack));
												printf("%d\n", temp);
												break;
								case DUP:
												temp = peek(&(rt->stack));
												push(&(rt->stack), temp);
												break;
								case EXTR:
												extract(&(rt->stack), argument);
												break;
								case ENDOFFILE:
												break;
								case ERROR:
												printf("Unrecognized command\n");
												break;
				}
				return;
}
