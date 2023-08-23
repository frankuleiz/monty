#include "monty.h"
/**
 * _pint -  prints top element on a stack
 * @stack: pointer to stack
 * @line_number: where the instruction appears
 * Return: 1(success), 2(Failure)
 */
void _pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d" can't pint, stack empty\n", line_number);
		fclose(file);
		_free(*stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
