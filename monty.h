#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/**
* struct stack_s - doubly linked list representation of a stack (or queue)
* @n: integer
* @prev: points to the previous element of the stack (or queue)
* @next: points to the next element of the stack (or queue)
*
* Description: doubly linked list node structure
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
* struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO Holberton project
*/
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void funcs(char *str, stack_t **head, unsigned int line_number);
int _isdigit(char *m);
int isPush(char *toke1, char *toke2);
void pallFunc(stack_t **stack, unsigned int line_number);
void pushFunc(stack_t **stack, int line_number);
void free_stack(stack_t **head);
void pintFunc(stack_t **stack, unsigned int line_number);
void popFunc(stack_t **stack, unsigned int line_number);
void swapFunc(stack_t **stack, unsigned int line_number);
void addFunc(stack_t **stack, unsigned int line_number);
void nopFunc(stack_t **stack, unsigned int line_number);
void emer_exit(char *line, FILE *file, stack_t **head);

#endif /* MONTY_H */
