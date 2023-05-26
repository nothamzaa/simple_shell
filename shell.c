#include "shell.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *command;

    while (1)
    {
        command = read_command();
        if (command == NULL)
            break;

        execute_command(command);

        free(command);
    }

    return 0;
}

/**
 * read_command - Reads a command from the user
 *
 * Return: The command entered by the user (or NULL on failure)
 */
char *read_command(void)
{
    char *command = NULL;
    size_t bufsize = 0;

    printf("#cisfun$ ");

    if (getline(&command, &bufsize, stdin) == -1)
    {
        if (feof(stdin))
            return NULL;
        else
        {
            perror("getline");
            exit(EXIT_FAILURE);
        }
    }

    /* Remove the trailing newline character */
    command[strcspn(command, "\n")] = '\0';

    return command;
}

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 */
void execute_command(char *command)
{
    pid_t pid;
    int status;

    pid = fork();
    if (pid == -1)
    {
        perror("fork");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0)
    {
        if (execlp(command, command, NULL) == -1)
        {
            perror("execlp");
            exit(EXIT_FAILURE);
        }
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
}
