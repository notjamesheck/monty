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

/**
  * addFunc - a function that prints the sum of the first two elements
  * of a stack
  * @head: takes a struct to a stack
  * @n: line number to file
  * Return: void
  */
void addFunc(struct stack_t **head, int n)
{
int sum = 0;
int i = 0;

if ((*head)->next == NULL)
	{
	printf("L%d: can't add, stack too short", n);
	exit(EXIT_FAILURE);
	}
while ((*head) != (*head)->next->next->next)
	{
	head = head->next;
	i++;
	sum += stack_t[i];
	}
printf("%d\n", sum);
}

/**
  * swapFunc - a function that swaps the first two elements
  * of a stack
  * @head: a stack
  * @n: line number from file
  * Return: void
  */
void swapFunc(struct stack_t **head, int n)
{
stack_t **temp;

temp = head;

if (temp == NULL)
	{
	printf("L%d: can't swap, stack too short\n", n);
	exit(EXIT_FAILURE);
	}
while (temp != temp->next->next->next)
{
	temp = temp->next;
	temp->next->next = head->next;
	head->next = temp->next->next->next;
	temp->next->next->prev = head;
	head->next->prev = temp->next->next;
}
}

/**
  * nopFunc - a function that does nothing
  * @head: a pointer to the struct of doubly linked list
  * @n: line number from file
  * Return: void
  */

void nopFunc(struct stack_t **head, int n)
{
void(*head);
void(n);
}

/**
  * popFunc - a function that deletes the head node of a stack
  * @head: pointer to head of stack
  * @n: line number from file
  * Return: void
  */
void popFunc(struct stack_t **head, int n)
{
stack_t *temp;

temp = *head;
if (temp == NULL)
{
	printf("L%d: can't pop an empty stack", n);
	exit(EXIT_FAILURE);
}
while ((*head) != (*head)->next->next)
{
	(*head) = (*head)->next;
	(*head)->next->prev = NULL;
	free(temp);
}
}
