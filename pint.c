#include "monty.h"
/**
 * _pint - print the value at the top of stack followed by a newline
 * @stack: pointer to stack
 * @line: line number
 */
void _pint(stack_t **stack, unsigned int line)
{
	if (!valid_stack(stack))
	{
		printf("L%u: can't pint, stack empty\n", line);
		global.mode = 2;
		return;
	}
	printf("%d\n", (*stack)->n);
}
