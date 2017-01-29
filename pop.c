#include "monty.h"
/**
 * pop - Remove the top item from the stack
 * @stack: the stack
 * @line: line number
 */
void pop(stack_t **stack, unsigned int line)
{
    stack_t *tmp;

    if (!valid_stack(stack))
    {
        global.mode = 2;
        op_function_error(line, "can't pop an empty stack");
        return;
    }

    tmp = *stack;
    if (tmp->next != NULL)
        tmp->next->prev = NULL;
    *stack = tmp->next;
    free(tmp);
}    
