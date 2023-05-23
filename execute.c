#include "shell.h"

/**
 * execute_command - Executes a command in the shell
 * @args: Array of command arguments
 * Return: 1 if successful
 */
int execute_command(char **args)
{
	if (is_builtin(args))
		return 1;

	pid_t pid, wpid;
	int status;

	pid = fork();
	if (pid == 0)
	{
		/* Child process */
		if (execvp(args[0], args) == -1)
		{
			perror("execvp");
			exit(1);
		}
	}
	else if (pid < 0)
	{
		/* Error forking */
		perror("fork");
	}
	else
	{
		/* Parent process */
		do
		{
			wpid = waitpid(pid, &status, WUNTRACED);
		} while (!WIFEXITED(status) && !WIFSIGNALED(status));
	}

	return 1;
}

/**
 * is_builtin - Checks if a command is a built-in
 * @args: Array of command arguments
 * Return: 1 if built-in, 0 if not
 */
int is_builtin(char **args)
{
	if (args == NULL || args[0] == NULL)
		return 0;

	if (_strcmp(args[0], "exit") == 0 || _strcmp(args[0], "env") == 0)
		return 1;

	return 0;
}
