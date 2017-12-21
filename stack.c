#include "monty.h"
/* STACK.C */
/**
* pushFunc - push to top of stack, init stack if empty
* @head: head node, top of stack
* @n: value for new head node
* Return: 0
*/
int pushFunc(stack_t **head, unsigned int n)
{
	/* if head == NULL, make new head */
	/* else, add node to top */
	/* error if malloc fails */
	/* fprintf(stderr, "Error: malloc failed\n"); */
	/* exit(EXIT_FAILURE); */
	stack_t *new = (stack_t *) malloc(sizeof(stack_t));

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
		*head = new;
		/*printf("made head with val %d\n", (*head)->n);*/
		return (0);
	}
	new->prev = NULL;
	new->next = *head;
	(*head)->prev = new;
	*head = new;
	/*printf("made head with val %d\n", (*head)->n);*/
	return (0);
}

/**
* pallFunc - print all of stack
* @head: pointer to top of stack
* @n: line number
* Return: int, print stack to stdout
*/
void pallFunc(stack_t **head, __attribute__((unused)) unsigned int n)
{
	/*printf("in pallFunc\n");*/
	if (head == NULL)
	{
		exit(EXIT_FAILURE); }
	while ((*head)->next != NULL)
	{
		printf("%d\n", (*head)->n);
		*head = (*head)->next;
	}
	printf("%d\n", (*head)->n);
}
