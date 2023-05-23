#include "shell.h"

/**
 * execute - Execute shell commands
 * @args: Input arguments/commands
 * Return: Returns status code
 */

int execute(char **args)
{
    pid_t pid;
    int status = 0;

    if (args[0] == NULL)
        return (status);

    pid = fork();
    if (pid == 0)
    {
        if (execvp(args[0], args) == -1)
        {
            perror(args[0]);
            exit(EXIT_FAILURE);
        }
    }
    else if (pid < 0)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else
    {
        do {
            if (waitpid(pid, &status, WUNTRACED) == -1)
            {
                perror("waitpid");
                exit(EXIT_FAILURE);
            }
        } while (!WIFEXITED(status) && !WIFSIGNALED(status));
    }
    return (status);
}
