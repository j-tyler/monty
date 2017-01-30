#include "monty.h"
/**
 * _mod - computes the remainder of the second top element by the top
 * @stack: the stack
 * @line: line number
 */
void _mod(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;

	if (!valid_top_two(stack))
	{
		printf("L%u: can't mod, stack too short\n", line);
		global.mode = 2;
		return;
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line);
		global.mode = 2;
		return;
	}

	temp->next->n %= temp->n;
	pop(stack, line);
}
