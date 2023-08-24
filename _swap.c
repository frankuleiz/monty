#include "monty.h"

/**
 * _swap - a function that swaps the tp two elements
 * @stack: the pointer to the head of the stack
 * @line_number: displays the instructions
 * Return: 1(success) or 2 (on failure)
 */

void _swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *bottom;

	if ((*stack == NULL) || ((*stack)->next == NULL))
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	else if (*stack)
	{
		top = *stack;
		bottom = top->next;
		*stack = bottom;
		top->next = bottom->next;
		if (bottom->next != NULL)
		{
			bottom->next->prev = top;
		}
		bottom->prev = NULL;
		bottom->next = top;
		top->prev = bottom;
	}
}
