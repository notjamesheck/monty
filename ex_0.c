#include "monty.h"
/* STACK.C */
/**
* pushFunc - push to top of stack, init stack if empty
* @head: head node, top of stack
* @n: value for new head node
* Return: 0
*/
void pushFunc(stack_t **head, int n)
{
	stack_t *new = malloc(sizeof(stack_t));

	/*printf("in pushFunc now\n");*/
	if (new == NULL)
	{
		printf("Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = n;
	if (*head == NULL)
	{
		new->next = NULL;
		new->prev = NULL;
		(*head) = new;
		/*printf("made head with val %d\n", (*head)->n);*/
	}
	else
	{
		new->prev = NULL;
		new->next = (*head);
		(*head)->prev = new;
		(*head) = new;
	}
	/*printf("made head with val %d\n", (*head)->n);*/
}

/**
* pallFunc - print all of stack
* @head: pointer to top of stack
* @n: line number
* Return: int, print stack to stdout
*/
void pallFunc(stack_t **head, unsigned int n)
{
	stack_t *temp = *head;

	n = n;
	/*printf("in pallFunc\n");*/
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
