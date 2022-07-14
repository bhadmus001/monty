#include"monty.h"
/**
 * op_sub - Subtracts stack's top element from the second stack's top element.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the file.
 * Return: Void. Nothing.
 */
void op_sub(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n = (*stack)->next->n - (*stack)->n;
		op_pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		free_files(stack);
		exit(EXIT_FAILURE);
	}
}
