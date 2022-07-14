#include "monty.h"
/**
 * main - Opens a monty file.
 * @argc: Argument's count.
 * @argv: Argument's vector.
 * Return: EXIT_FAILURE on failure. EXIT_SUCCESS on succes.
 */
int main(int argc, char *argv[])
{
	struct stat st;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	if (stat(argv[1], &st) == 0)
	{
		if ((st.st_mode & S_IFMT) != S_IFREG)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			free_files(NULL);
			exit(EXIT_FAILURE);
		}
		opt.file = fopen(argv[1], "r");
		if (!opt.file)
		{
			fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
			free_files(NULL);
			exit(EXIT_FAILURE);
		}
		readfile();
	}
	else
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		free_files(NULL);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
