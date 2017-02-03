#include "monty.h"
/**
 * _pstr - Print string from the stack
 * @stack: the stack
 * @line: line number
 */
void _pstr(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	if (!valid_stack(stack))
	{
		printf("\n");
		return;
	}

	tmp = *stack;
	while (*tmp >= 1 && *tmp <= 127)
	{
		printf("%c", *tmp);
		tmp = tmp->next;
	}
	printf("\n");
}
