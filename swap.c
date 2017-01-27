#include "monty.h"
/**
 * swap - swap the values of the top two nodes
 * @stack: the stack
 * @line: line number
 */
void swap(stack_t **stack, unsigned int line)
{
    int tmp;

    if (**stack == NULL || *stack == NULL || (*stack)->next == NULL)
    {
        global.mode = 2;
        op_function_error(line, "can't swap, stack too short");
        return;
    }

    tmp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = tmp;
}
