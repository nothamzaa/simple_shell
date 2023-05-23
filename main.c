#include "minishell.h"

/**
 * main - entry point
 *
 * @argc: number of arguments given to the program
 * @argv: arguments list
 *
 * Return: returns the value of the last executed command
 */
int main(int argc, char **argv)
{
	char *cmdline = NULL;
	char prompt[] = "(hsh) ";
	Bool status = true;

	(void)argc; /* Silence unused parameter warning */
	name = (argc > 0) ? argv[0] : NULL;

	while (status)
	{
		write(STDOUT_FILENO, prompt, strlen(prompt));
		cmdline = get_user_input();
		/* Process the command */
	}

	free(cmdline); /* Remember to free dynamically allocated memory */

	return 0;
}
