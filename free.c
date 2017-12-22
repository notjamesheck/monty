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
	temp = (*head);
	while (temp)
	{
		printf("freeing\n");
		temp = (*head)->next;
		temp->prev = NULL;
		free(*head);
		(*head) = temp;
	}
	if (*head == NULL)
		printf("freed something\n");
}
