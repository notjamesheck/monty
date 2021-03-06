#include "monty.h"
/**
* main - main function to execute monty byte code commands
* @argc: argument count
* @argv: argument vector
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	FILE *file;
	size_t len;
	char *toke1, *toke2, *line = NULL, *delims = "\n\t\r ";
	unsigned int line_number = 1, test = 1;
	int a = 0;
	stack_t *head = NULL;

	if (argc != 2) /* check if correct number of args */
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (file == NULL) /* check if fopen is successful */
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
	while ((getline(&line, &len, file)) != -1) /* get each line of file */
	{
		toke1 = strtok(line, delims);
		if (toke1)
		{
			toke2 = strtok(NULL, delims);
			test = isPush(toke1, toke2);
			if (test == 0)
			{
				a = atoi(toke2);
				pushFunc(&head, a); }
			else if (test == 2)
			{
				printf("L%d: usage: push integer\n", line_number);
				emer_exit(line, file, &head); }
			else
			{
				funcs(toke1, &head, line_number); } }
		line_number++, test = 1; }
	free(line);
	fclose(file);
	free_stack(&head);
	exit(EXIT_SUCCESS); }
