#include "shell.h"

int main(void)
{
	char *line = NULL;
	size_t bufsize = 0;
	ssize_t linelen;
	char **args;
	int status;

	while (1)
	{
		printf("$ ");
		linelen = getline(&line, &bufsize, stdin);
		if (linelen == -1)
		{
			free(line);
			break;
		}
		args = tokenize_line(line);
		if (args == NULL)
			continue;
		status = execute_command(args);
		free_args(args);
		if (status == 0)
			break;
	}

	return 0;
}
