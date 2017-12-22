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
	char *line = NULL;
	ssize_t nread;
	char *toke1, *toke2, *delims = "\n\t\r ";
	unsigned int line_number = 1, test = 1;
	stack_t *head = NULL;

	if (argc != 2) /* check if correct number of args */
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL) /* check if fopen is successful */
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); 
	}
	while ((nread = getline(&line, &len, file)) != -1) /* get each line of file */
	{
		toke1 = strtok(line, delims);
		printf("made token1 %s\n", toke1);
		if (toke1)
		{
			toke2 = strtok(NULL, delims);
			printf("made token2 %s\n", toke2);
			test = isPush(toke1, toke2);
			if (test == 0)
			{
				printf("going into push\n");
				test = 1;
				pushFunc(&head, line_number); 
			}
			else
			{
				printf("going into funcs\n");
				funcs(toke1, &head, line_number);
			}
		}
		line_number++;
	}
	free(line);
	fclose(file);
	free_stack(&head);

	return (0);
}
