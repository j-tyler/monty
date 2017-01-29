#include "monty.h"
/**
 * _add - Add top two items of stack
 * @stack: the stack
 * @line: line number
 */
void _add(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;

	if (!valid_top_two(stack))
	{
		printf("L%u: can't add, stack too short\n", line);
		global.mode = 2;
		return;
	}
	temp->next->n += temp->n;
	pop(stack, line);
}
