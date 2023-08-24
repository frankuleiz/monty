#include "monty.h"
/**
 * main - main method
 * @argc: number of args
 * @argv: command line args
 * Return: 0(success)
 */
int main(int argc, char *argv[])
{
	stack_t *head = NULL;
	char *operator_array[2], *temp, str[1024];
	struct stat file_info;
	size_t bufsize = 1024, line_count = 0;
	void (*operator_function)(stack_t **stack, unsigned int);

	if (argc != 2)
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	stat(argv[1], &file_info);
	if (!(S_ISREG(file_info.st_mode)) || access(argv[1], R_OK) != -0)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (fgets(str, bufsize, file))
	{
		line_count++;
		operator_array[0] = strtok(str, "\n ");
		if (operator_array[0] == NULL)
			_nop(&head, line_count);
		else if (strcmp("push", operator_array[0]) == 0)
		{
			temp = strtok(NULL, "\n ");
			_push(&head, line_count, temp);
		}
		else if (operator_array[0] != NULL && operator_array[0][0] != '#')
		{
			operator_function = go(operator_array[0], line_count, &head);

			if (operator_function == NULL && line_count == 0)
				fprintf(stderr, "L%ld: unknown instruction %s\n",
						line_count, operator_array[0]), exit(EXIT_FAILURE);
			operator_function(&head, line_count);
		}
		if (strcmp(operator_array[0], "push") != 0 &&
				strcmp(operator_array[0], "pall") != 0 &&
				strcmp(operator_array[0], "pint") != 0 &&
				strcmp(operator_array[0], "swap") != 0 &&
				strcmp(operator_array[0], "add") != 0 &&
				strcmp(operator_array[0], "pop") != 0)
			printf("%s\n", str);
	}

	fclose(file), _free(head);
	return (0);
}
