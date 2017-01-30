#include "monty.h"
/**
 * _swap - swap the values of the top two nodes
 * @stack: the stack
 * @line: line number
 */
void _swap(stack_t **stack, unsigned int line)
{
	int tmp;

	if (!valid_top_two(stack))
	{
		global.mode = 2;
		op_function_error(line, "can't swap, stack too short");
		return;
	}

	tmp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = tmp;
}
