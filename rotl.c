#include "monty.h"
/**
 * _rotl - Rotate the top item of the stack to the bottom
 * @stack: the stack
 * @line: line number
 */
void _rotl(stack_t **stack, unsigned int line)
{
	stack_t *old_head, *tmp;

	if (!valid_top_two(stack))
		return;

	old_head = global.stack;
	global.stack = global.stack->next;
	global.stack->prev = NULL;

	tmp = global.stack->next;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = old_head;
	old_head->next = NULL;
}
