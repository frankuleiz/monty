#include "monty.h"
/**
 * _free - free stack
 * @stack: points to the stack
 * Return: void
 */
void _free(stack_t *stack)
{
	if (stack)
	{
		_free(stack->next);
		free(stack);
	}
}
