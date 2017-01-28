/**
* pint - print the value at the top of stack followed by a newline
* @stack: pointer to stack
* @line: line number
*/
void pint(stack_t **stack, unsigned int line)
{
	if (stack_len(*stack) < 1 || *stack == NULL)
	{
		printf("L%u: can't pint, stack empty\n", line);
		exit(EXIT_FAILURE);
	}
	print("%d\n", (*stack)->n);
}