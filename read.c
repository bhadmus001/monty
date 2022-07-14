#include "monty.h"
/**
 *readfile - reads a specific file.
 *Return: Void. Nothing.
 */
void readfile(void)
{
	stack_t *op_stack = NULL;
	size_t buf_size = 1024;
	char *op_code, *op_arg;
	unsigned int line = 0;
	void (*f)(stack_t**, unsigned int);

	opt.buffer = malloc(1024);
	while (getline(&(opt.buffer), &buf_size, opt.file) != -1)
	{
		line++;
		op_code = strtok(opt.buffer, "\n\t\r ");
		opt.element = strtok(NULL, "\n\t\r ");
		if (op_code)
		{
			f = op_handler(op_code);
			if (f)
				f(&op_stack, line);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n",
				line, op_code);
				exit(EXIT_FAILURE);
			}
		}
	}
	free_files(&op_stack);
	(void)op_code;
	(void)op_arg;
}
