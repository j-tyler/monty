#include "monty.h"
/**
 * _push - Push onto the stack
 * @stack: the stack
 * @line: line number
 */
void _push(stack_t **stack, unsigned int line)
{
	stack_t *tmp;

	/* if mode 0, stack */
	if (stack == NULL)
		printf("DEBUG: We made a mistake creating our stack\n");
	if (*stack == NULL)
	{
		global.stack = create_node();
		if (global.mode == 2)
			printf("L%u: usage: push integer\n", line);
	}
	else
	{
		tmp = *stack;
		global.stack = create_node();
		if (global.mode == 2)
		{
			printf("L%u: usage: push integer\n", line);
			return;
		}
		global.stack->next = tmp;
	}
	/* if mode 1, queue */
}
/**
 * create_node - creates a new node, returns pointer to node
 * Return: pointer to node
 */
stack_t *create_node(void)
{
	stack_t *node;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
		exit_with_error("Error: malloc failed");

	node->n = parse_number();
	node->prev = NULL;
	node->next = NULL;
	return (node);
}
