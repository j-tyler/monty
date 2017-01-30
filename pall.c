#include "monty.h"
/**
 * _pall - Print all items in the stack
 * @stack: the stack
 * @line: line number
 */
void _pall(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	(void) line;
	if (!valid_stack(stack))
		return;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}
