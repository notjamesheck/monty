#include "monty.h"
/* FUNCS.C */
/**
* funcs - function pointers for opcodes
* @str: string from line of file
* @head: head node of doubly linked list
* @line_num: line number from file, for errors
* Return: 0
*/
int funcs(char *str, stack_t **head, int line_num)
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
	/*printf("i'm in funcs\n");*/
	while (c[i].opcode != NULL)
	{
		comp = strcmp(str, c[i].opcode);
		if (comp == 0)
		{
			(c[i].f)(head, line_num);
			return (0);
		}
		i++;
	}

	return (0);
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
* eval - evaluate where these values go
* @head: head node
* @toke1: 1st token of line
* @toke2: 2nd token of line
* @line_num: line number
* Return: void
*/
int eval(stack_t **head, char *toke1, char *toke2, int line_num)
{
	int test1 = strcmp(toke1, "push");
	int test2 = _isdigit(toke2);
	int tokeint;

	/*printf("in eval function\n");*/
	/*printf("test1: %d\n", test1);*/
	/*printf("test2: %d\n", test2);*/
	if (test1 == 0 && test2 == 0)
	{
		tokeint = atoi(toke2);
		/*printf("tokeint: %d\n", tokeint);*/
		/*printf("going into pushFunc\n");*/
		pushFunc(head, tokeint);
		return (0);
	}
	else if (test1 == 0 && test2 != 0)
	{
		printf("L%d: usage: push integer\n", line_num);
		exit(EXIT_FAILURE);
	}
	else
	{
		/*printf("going into funcs\n"); */
		funcs(toke1, head, line_num);
		return (0);
	}

	return (0);
}
