#include "monty.h"
/**
 * add - Add top two items of stack
 * @stack: the stack
 * @line: line number
 */
void add(stack_t **stack, unsigned int line)
{
	stack_t *temp;

	temp = *stack;

	if (stack_len(*stack) < 2 || stack == NULL)
	{
		printf("L%u: can't add, stack too short\n", line);
		exit(EXIT_FAILURE);
	}
	temp->next->n += temp->n;
	pop(stack, line);
}
