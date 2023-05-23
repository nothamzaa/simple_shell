#include "shell.h"

/**
 * readline - Reads a line of input from stdin
 * Return: The line of input
 */
char *readline(void)
{
	char *line = NULL;
	size_t bufsize = 0;

	if (getline(&line, &bufsize, stdin) == -1)
	{
		free(line);
		return NULL;
	}

	return line;
}
