#include "monty.h"
/**
 * _mul - multiply top two items of stack
 * @stack: the stack
 * @line: line number
 */
void _mul(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;

	if (!valid_top_two(stack))
	{
		printf("L%u: can't mul, stack too short\n", line);
		global.mode = 2;
		return;
	}
	temp->next->n *= temp->n;
	pop(stack, line);
}
