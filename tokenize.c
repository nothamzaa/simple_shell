#include "shell.h"

/**
 * tokenize_line - Tokenizes a line of input
 * @line: The input line
 * Return: Array of tokens
 */
char **tokenize_line(char *line)
{
	char *token;
	char **tokens = malloc(sizeof(char *) * bufsize);
	int position = 0;

	if (tokens == NULL)
	{
		perror("malloc");
		exit(1);
	}

	token = strtok(line, " \t\r\n\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;

		if (position >= bufsize)
		{
			bufsize += TOKEN_BUFSIZE;
			tokens = realloc(tokens, sizeof(char *) * bufsize);
			if (tokens == NULL)
			{
				perror("realloc");
				exit(1);
			}
		}

		token = strtok(NULL, " \t\r\n\a");
	}
	tokens[position] = NULL;
	return tokens;
}

/**
 * free_args - Frees the memory allocated for an array of arguments
 * @args: The array of arguments
 */
void free_args(char **args)
{
	int i;
	for (i = 0; args[i] != NULL; i++)
		free(args[i]);
	free(args);
}
