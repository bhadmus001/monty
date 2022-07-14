#include "monty.h"
/**
 * op_pstr - Prints the string starting at stack's top, followed by a new line.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 * Return: Void. Nothing
 */
void op_pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *new = *stack;
	(void) line_number;

	while (new->next)
	{
		if (new->next == 0 || new->n < 32 || new->n > 177)
			break;

		printf("%c", new->n);
		new = new->next;

	}
	printf("\n");
}
