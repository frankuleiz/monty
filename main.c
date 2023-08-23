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
	char *str = NULL, *operator_array[2], *temp;
	size_t bufsize = 1024, line_count = 0;
	void (*operator_function)(stack_t **stack, unsigned int);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n"), exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]), exit(EXIT_FAILURE);
	while (1)
	{
		if (fgets(str, bufsize, file) == NULL)
			break;
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
	}
	fclose(file), free(str), _free(head);
	return (0);
}
