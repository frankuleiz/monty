#include "monty.h"
/**
 * _push - a function that push an element on top of a stack
 * @stack: the pointer to the top of the stack
 * @line_number: displays the instructions
 * @temp: the pointer to the instructions
 * Return: 1 (success) or 2 (on failure)
 */

void _push(stack_t **stack, unsigned int line_number, char *temp)
{
	stack_t *new;
	(void)line_number;

	if (temp == NULL || _isdigit(temp) == 1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		fclose(file);
		_free(*stck);
		exit(EXIT_FAILURE);
		if (_isdigit(temp) == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(file);
			_free(*stack);
			exit(EXIT_FAILURE);
		}

	}
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		fclose(file);
		exit(EXIT_FAILURE);
	}
	new->n = atoi(temp);
	new->next = NULL;
	new->prev = NULL;
	if (*stack)
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	*stack = new;
}
