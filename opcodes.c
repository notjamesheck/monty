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
		printf("L %d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*head)->n);
}

/**
* addFunc - a function that prints the sum of the first two elements
* @head: takes a struct to a stack
* @line_number: line number to file
* Return: void
*/
void addFunc(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if ((*head)->next == NULL)
	{
		printf("L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE); }
	(*head)->n += (*head)->next->n;
	temp = (*head)->next;
	(*head)->next = (*head)->next->next;
	(*head)->next->prev = (*head);
	free(temp);
}

/**
* swapFunc - a function that swaps the first two elements
* @head: a stack
* @line_number: line number from file
* Return: void
*/
void swapFunc(stack_t **head, unsigned int line_number)
{
	int temp;

	if ((*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE); }
	temp = (*head)->n;
	(*head)->n = (*head)->next->n;
	(*head)->next->n = temp;
}

/**
* nopFunc - a function that does nothing
* @head: a pointer to the struct of doubly linked list
* @line_number: line number from file
* Return: void
*/
void nopFunc(stack_t **head, unsigned int line_number)
{
	head = head;
	line_number = line_number;
}

/**
* popFunc - a function that deletes the head node of a stack
* @head: pointer to head of stack
* @line_number: line number from file
* Return: void
*/
void popFunc(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	temp = (*head);
	if (temp == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*head)->next == NULL)
	{
		free(temp);
	}
	else
	{
		(*head) = (*head)->next;
		(*head)->prev = NULL;
		free(temp);
	}
}
