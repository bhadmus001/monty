#include "monty.h"
/**
 *op_pall - Prints all the values on the stack, starting from the stack's top.
 *@stack: Pointer to the top of the stack.
 *@line_number: Line number in the file.
 *Return: Void. Nothing.
 */
void op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *new = (*stack);

	while (new)
	{
		printf("%d\n", new->n);
		new = new->next;
	}
	(void)line_number;
}
