#include "monty.h"
/**
* free_stack - entry point
* @head: pointer to head
* Return: void
*/
void free_stack(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
	{
		return; }
	temp = head;
	while (head->next != NULL)
	{
		temp = head;
		head = head->next;
		free(temp); }
	temp = head;
	free(temp);
	head = NULL;
}
