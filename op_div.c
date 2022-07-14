#include "monty.h"
/**
 *op_div - Divides the stack's second top element by the stack's top element.
 *@stack: Pointer to the top of the stack.
 *@line_number: Line number in the file.
 *Return: Void. Nothing.
 */
void op_div(stack_t **stack, unsigned int line_number)
{
	if (*stack && (*stack)->next)
	{
		(*stack)->next->n = (*stack)->next->n / (*stack)->n;
		op_pop(stack, line_number);
	}
	else
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		free_files(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
}
