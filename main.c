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
	char *toke1, *toke2, *delims = "\n\t ";
	int line_num = 1;
	stack_t *head = NULL;

	if (argc != 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE); }
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE); }
	while ((nread = getline(&line, &len, file)) != -1)
	{
		toke1 = strtok(line, delims);
		if (toke1)
		{
			toke2 = strtok(NULL, delims);
			if (toke2 != NULL)
			{
				eval(&head, toke1, toke2, line_num); }
			else
			{
				funcs(toke1, &head, line_num); }
		}
		line_num++; }
	if (head != NULL)
		free_stack(head);

	free(line);
	fclose(file);
	return (0);
}
