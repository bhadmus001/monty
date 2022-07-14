#include "monty.h"
/**
 *op_handler - Matches an opcode with the correct operation.
 *@op_code: Op Code to match.
 *Return: Void. Nothing.
 */
void (*op_handler(char *op_code))(stack_t **, unsigned int)
{
	instruction_t op_instruction[] = {
		{"push", op_push},
		{"pall", op_pall},
		{"pint", op_pint},
		{"pop", op_pop},
		{"swap", op_swap},
		{"add", op_add},
		{"nop", op_nop},
		{"sub", op_sub},
		{"div", op_div},
		{"mul", op_mul},
		{"mod", op_mod},
		{"pstr", op_pstr},
		{NULL, NULL}
	};
	int i = 0;

	for (; op_instruction[i].opcode != NULL; i++)
	{
		if (strcmp(op_instruction[i].opcode, op_code) == 0)
		{
			return (op_instruction[i].f);
		}
	}
	return (NULL);
}
