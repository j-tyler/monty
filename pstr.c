#include "monty.h"
/**
 * _pstr - Print string from the stack
 * @stack: the stack
 * @line: line number
 */
void _pstr(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	(void) line;
	if (!valid_stack(stack))
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (tmp->n >= 1 && tmp->n <= 127)
	{
		printf("%c", tmp->n);
		tmp = tmp->next;
	}
	printf("\n");
}
