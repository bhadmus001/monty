#include "monty.h"
/**
 *op_swap - Swaps the top two elements of the stack.
 *@stack: Pointer to the top of the stack.
 *@line_number: Line number in the file.
 *Return: Void. Nothing.
 */
void op_swap(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	int i;
	(void) line_number;

	if (!new || !new->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		free_files(stack);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->next != NULL)
	{
		i = (*stack)->n;
		(*stack)->n = (*stack)->next->n;
		(*stack)->next->n = i;
	}
}
