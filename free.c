#include "monty.h"
/**
 *free_files - Free space of a specific function.
 *@stack: Pointer to the satck.
 *Return: Void. Nothing.
 */
void free_files(stack_t **stack)
{
	stack_t *content;

	if (stack)
	{
		content = *stack;
		while (*stack)
		{
			content = (*stack)->next;
			free(*stack);
			*stack = content;
		}
	}
	if (opt.buffer)
		free(opt.buffer);
	if (opt.file)
		fclose(opt.file);
}
