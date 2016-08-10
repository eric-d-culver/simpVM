#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void push(node** stack, int data) {
				node* newNode = malloc(sizeof(node));
				newNode->data = data;
				newNode->next = *stack;
				newNode->prev = NULL;
				*stack = newNode;
				return;
}

int pop (node** stack) {
				if (*stack==NULL) {
								/* empty stack */
								return -1;
				} else {
			  				node* temp = *stack;
								int value = temp->data;
								*stack = temp->next;
								free(temp);
								(*stack)->prev = NULL;
								return value;
				}
}

void freeStack(node** stack) {
				node* temp = *stack;

				if (temp==NULL) {
								/* empty stack */
								return;
				}

				/* find bottom of stack */
				while (temp->next != NULL) {
								temp = temp->next;
				}

				/* free to top of stack */
				while (temp != *stack) {
								temp = temp->prev;
								free(temp->next);
								temp->next = NULL;
				}

				free(temp);
				*stack = NULL;

				return;
}

void stackTest(node* stack) {
				int number;

				if (stack==NULL) {
								printf("Stack empty\n");
				}

				push(&stack, 23);
				push(&stack, 5);
				push(&stack, 3);
				push(&stack, 2);

				printf("Should output: 2,3,5\n");

				number = pop(&stack);
				printf("%d\n", number);
				number = pop(&stack);
				printf("%d\n", number);
				number = pop(&stack);
				printf("%d\n", number);

				if (stack==NULL) {
								printf("Empty again.\n");
				} else {
								number = pop(&stack);
								printf("One more: %d\n", number);
				}

				return;
}
