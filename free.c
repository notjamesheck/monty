#include "monty.h"
/**
* free_stack - entry point
* @head: pointer to head
* Return: void
*/
void free_stack(stack_t **head)
{
	stack_t *temp;

	/*printf("freeing something\n");*/
	while (*head)
	{
		/*printf("freeing\n");*/
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
	/*if (*head == NULL)*/
		/*printf("freed something\n");*/
}

/**
* emer_exit - free and exit failure
* @line: from getline
* @file: from fopen
* @head: stack
* Return: void
*/
void emer_exit(char *line, FILE *file, stack_t **head)
{
	free(line);
	fclose(file);
	free_stack(head);
	exit(EXIT_FAILURE);
}
