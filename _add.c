#include "monty.h"

/**
 * _add - fuctions that adds the to two elements
 * @stack: pointer to the head of the stack
 * @line_number: displays the instructions
 * Return: 1 0n (success) or 2 (on failure)
 */

void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *first, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	first = *stack;
	second = first->next;

	if (second == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n += first->n;
	*stack = second;
	(*stack)->prev = NULL;
	free(first);
}
