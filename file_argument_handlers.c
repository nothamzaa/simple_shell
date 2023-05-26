#include "header.h"

/**
 * rd_file - Reads all commands from the argument File
 * @file: File containing commands
 * @argv: Arguments passed
 * Return: -1 or 0
 */

void rd_file(char *file, char **argv)
{
	FILE *fp;
	char *line = NULL;
	size_t len = 0;
	int count = 0;

	fp = fopen(file, "r");
	if (fp == NULL)
	{
		err_file(argv, count);
		exit(127);
	}
	while ((getline(&line, &len, fp)) != -1)
	{
		count++;
		trt_file(line, count, fp, argv);
	}
	if (line)
		free(line);
	fclose(fp);
	exit(0);
}

/**
 * trt_file - Parse the commands and handle their execution
 * @line: Line from file
 * @count: Error counter
 * @fp: File descriptor
 * @argv: Command line arguments
 */

void trt_file(char *line, int count, FILE *fp, char **argv)
{
	char **cmd;
	int stat = 0;

	cmd = parse_cmmd(line);
	if (_strncmp(cmd[0], "exit", 4) == 0)
		exit_bul_f_file(cmd, line, fp);
	else if (check_builtin(cmd) == 0)
	{
		stat = handle_builtin(cmd, stat);
		free(cmd);
	}
	else
	{
		stat = check_cmd(cmd, line, count, argv);
		free(cmd);
	}
}

/**
 * exit_bul_f_file - Exit statusof the handler for file input
 * @line: Line from a file
 * @cmd: Parsed command
 * @fd: File Descriptor
 */

void exit_bul_f_file(char **cmd, char *line, FILE *fd)
{
	int status;
	int i = 0;

	if (cmd[i] == NULL)
	{
		free(line);
		free(cmd);
		fclose(fd);
		exit(errno);
	}
	while (cmd[1][i])
	{
		if (_isalpha(cmd[1][i++]) < 0)
			perror("Illegal number");
	}
	status = _atoi(cmd[1]);
	free(line);
	free(cmd);
	fclose(fd);
	exit(status);
}
