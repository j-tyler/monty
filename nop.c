#include "monty.h"
/**
 * nop - does nothing
 * @stack: pointer to stack
 * @line: line number
 * Return: Nothing
 */
void nop(stack_t **stack, unsigned int line)
{
	(void) stack;
	(void) line;
	exit(1);
}
