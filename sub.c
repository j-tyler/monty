#include "monty.h"
/**
 * sub - sub top two items of stack
 * @stack: the stack
 * @line: line number
 */
void sub(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp->next->n -= temp->n;
	pop(stack, line);
}
