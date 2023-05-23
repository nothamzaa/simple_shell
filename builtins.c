#include "shell.h"

/**
 * execute_builtin - Executes a built-in shell command
 * @args: Array of command arguments
 * Return: 0 if the command is exit, 1 if successful, -1 on failure
 */
int execute_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return 1;

	if (_strcmp(args[0], "exit") == 0)
		return 0;

	if (_strcmp(args[0], "env") == 0)
	{
		print_environment();
		return 1;
	}

	return -1;
}
