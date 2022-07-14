#include "monty.h"
/**
 *op_pop - Removes the top element of the stack.
 *@stack: Pointer to the stacks's top.
 *@line_number: Line number in the file.
 *Return: Void. Nothing.
 */
void op_pop(stack_t **stack, unsigned int line_number)
{
	stack_t *alloc = *stack;

	if (alloc)
	{
		if ((alloc)->next)
			(alloc)->next->prev = NULL;
		*stack = alloc->next;
		free(alloc);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_files(stack);
		exit(EXIT_FAILURE);
	}
}
