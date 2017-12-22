#include "monty.h"
/**
* free_stack - entry point
* @head: pointer to head
* Return: void
*/
void free_stack(stack_t **head)
{
	stack_t *temp;

	printf("freeing something\n");
	while (*head)
	{
		printf("freeing\n");
		temp = (*head)->next;
		free(*head);
		(*head) = temp;
	}
	if (*head == NULL)
		printf("freed something\n");
}
