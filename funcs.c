#include "monty.h"
/* FUNCS.C */
/**
* funcs - function pointers for opcodes
* @str: string from line of file
* @head: head node of doubly linked list
* @line_num: line number from file, for errors
* Return: 0
*/
void funcs(char *str, stack_t **head, unsigned int line_number)
{
	unsigned int i;
	int comp;

	instruction_t c[] = {
		{"pall", pallFunc},
		{"pint", pintFunc},
		{"pop", popFunc},
		{"swap", swapFunc},
		{"add", addFunc},
		{"nop", nopFunc},
		{NULL, NULL}
	};
	i = 0;

	printf("i'm in funcs\n");/**/
	while (c[i].opcode != NULL)
	{
		comp = strcmp(str, c[i].opcode);
		if (comp == 0)
		{
			printf("found a match, executing\n");
			(c[i].f)(head, line_number);
			return;
		}
		i++;
	}
	printf("L%d: unknown instruction %s\n", line_number, str);
	exit(EXIT_FAILURE);
}

/**
* _isdigit - test if digit
* @m: string to be tested
* Return: 0 on success, 1 if not digit
*/
int _isdigit(char *m)
{
	int i = 0;
	int c = strlen(m);

	if (m[0] == '-') /* check for negative */
	{
		i = 1;
	}
	for (; i < c; i++)
	{
		if (!(isdigit(m[i])))
		{
			return (1);
		}
	}

	return (0);
}

/**
* isPush - evaluate if push
* @toke1: 1st token of line
* @toke2: 2nd token of line
* Return: void
*/
int isPush(char *toke1, char *toke2)
{
	int test1 = 0;
	int test2 = 0;
	char str[] = "push";

	if (toke1)
		test1 = strcmp(toke1, str);

	if (toke2)
		test2 = _isdigit(toke2);


	printf("in isPush function\n");
	printf("test1: %d\n", test1);
	printf("test2: %d\n", test2);
	if (test1 == 0 && test2 == 0)
	{
		return (0);
	}

	return (1);
}
