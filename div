#include "monty.h"
/**
 * div - computes the rest of the division of the second top element by the top
 * @stack: the stack
 * @line: line number
 */
void div(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't div, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line);
		exit(EXIT_FAILURE);
	}

	temp->next->n /= temp->n;
	pop(stack, line);
}
