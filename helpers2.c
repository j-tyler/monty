#include "monty.h"
/**
 * valid_stack - Find if stack is initialized to have nodes
 * @stack: the stack
 * Return: 1 if items exist, 0 if not
 */
int valid_stack(stack_t **stack)
{
	if (stack == NULL || *stack == NULL)
		return (0);
	return (1);
}
/**
 * valid_top_two - Find if top two in stack are valid nodes
 * @stack: the stack
 * Return: 1 if items exist, 0 if not
 */
int valid_top_two(stack_t **stack)
{
	if (stack == NULL || *stack == NULL || (*stack)->next == NULL)
		return (0);
	return (1);
}
