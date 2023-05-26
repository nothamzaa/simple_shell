#include "header.h"

/**
 * main - Entry point to the program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: Returns condition
 */

int main(__attribute__((unused)) int argc, char **argv)
{
	char *input, **cmd, **commands;
	int count = 0, i, condition = 1, stat = 0;

	if (argv[1] != NULL)
		rd_file(argv[1], argv);
	signal(SIGINT, signal_to_handle);

	while (condition)
	{
		count++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
			continue;
		_history(input);
		commands = separator_(input);
		for (i = 0; commands[i] != NULL; i++)
		{
			cmd = parse_cmmd(commands[i]);
			if (_strcmpa(cmd[0], "exit") == 0)
			{
				free(commands);
				exit_bul(cmd, input, argv, count, stat);
			}
			else if (check_builtin(cmd) == 0)
			{
				stat = handle_builtin(cmd, stat);
				free(cmd);
				continue;
			}
			else
			{
				stat = checker_cmd(cmd, input, count, argv);
			}
/*if (commands[i + 1] == NULL)
{
free(commands);
break;
}*/
free(cmd);
}
free(input);
free(commands);
wait(&stat);
}
	return (stat);
}
