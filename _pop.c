#include "monty.h"

/**
 *  _pop - a function that removes the top element of the stack
 *  @stack: the pointer to the top of the stack
 *  @line_number: displays the instructions
 *  Return:1 (success) or 2 (on failure)
 */

void _pop(stack_t **stack, unsigned int line_number)
{
	stack_t *head;

	if ((*stack == NULL) || (stack == NULL))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	head = *stack;
	*stack = (*stack)->next;
	if (head->next)
	{
		head->next->prev = NULL;
	}
	free(head);
}
