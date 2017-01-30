#include "monty.h"
/**
 * _pchar - Add top two items of stack
 * @stack: the stack
 * @line: line number
 */
void _pchar(stack_t **stack, unsigned int line)
{
	if (!valid_stack(stack))
	{
		printf("L%u: can't pchar, stack empty\n", line);
		global.mode = 2;
		return;
	}
	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		printf("L%u: can't pchar, value out of range\n", line);
		global.mode = 2;
		return;
	}
	printf("%c\n", (*stack)->n);
}
