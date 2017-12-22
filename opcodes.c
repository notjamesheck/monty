#include "monty.h"

/**
* pintFunc - a function that prints the first element of a stack
* @head: a stack
* @line_number: line number to file
* Return: void, print head value
*/
void pintFunc(stack_t **head, unsigned int line_number)
{
	if ((*head) == NULL)
	{
		printf("L %d: can't pint, stack empty", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}
