#include "monty.h"
/**
 *op_pint - Prints the value at the top of the stack, followed by a new line.
 *@stack: Pointer to the stack.
 *@line_number: Line number in the file.
 *Return: Void. Nothing.
 */
void op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void) line_number;

	if (!new)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_files(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", new->n);
}
