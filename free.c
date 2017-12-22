#include "monty.h"
/**
* free_stack - entry point
* @head: pointer to head
* Return: void
*/
void free_stack(stack_t **head)
{
	stack_t *temp;
	
	printf("freeing memory now\n");
	if ((*head))
	{
		temp = (*head);
		while (temp)
		{
			temp = (*head)->next;
			free(*head);
			(*head) = temp;
		}
	}
} 
/**
* exit_stak - exit the program
* 
*
*
*/
/*exit_stak()*/
/*{*/
/*	close file */
/*	free buffer*/
/*	free tokens*/
/*	free list */
/*	error message*/
/*	exit*/
/*}*/
