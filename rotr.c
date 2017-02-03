#include "monty.h"
/**
 * _rotr - Bottom element of the stack rotates to the top
 * @stack: the stack
 * @line: line number
 */
void _rotr(stack_t **stack, unsigned int line)
{
	stack_t *old_tail, *tmp;

	if (!valid_top_two(stack))
		return;

	tmp = global.stack;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->prev->next = NULL
	old_tail = tmp;

	old_tail->next = global.stack;
	old_tail->prev = NULL;
	global.stack->prev = old_tail;
	global.stack = old_tail;
}
