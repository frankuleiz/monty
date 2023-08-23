#include "monty.h"
/**
 * _pall - a function that prints all elements in the stack
 * @stack: pointer to the head of a stack
 * @line_number: displays the instructions
 * Return: 1 (success) or 2 (on failure)
 */

void _pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;
	current = *stack;

	while (current != NULL)
	{
		printf("%d", current->n);
		current = current->next;
		printf("\n");
	}
}
