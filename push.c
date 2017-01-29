#include "monty.h"
/**
 * push - Push onto the stack
 * @stack: the stack
 * @line: line number
 */
void push(stack_t **stack, unsigned int line)
{
    // if mode 0, stack
    // if mode 1, queue
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

    node.n = parse_number();
    node.prev = NULL;
    node.next = NULL;
    return (node);
}
