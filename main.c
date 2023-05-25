#include "main.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_COMMAND_LENGTH 100

/**
 * execute_command - Executes the given command
 * @command: The command to execute
 */
void execute_command(const char *command)
{
    int status = system(command);
    if (status == -1)
    {
        printf("Error executing the command.\n");
    }
}

/**
 * main - Entry point of the program
 *
 * Return: Always 0
 */
int main(void)
{
    char command[MAX_COMMAND_LENGTH];

    while (1)
    {
        printf("simple_shell$ ");

        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            printf("\n");
            break;
        }

        command[strcspn(command, "\n")] = '\0';

        if (strcmp(command, "exit") == 0)
            break;

        execute_command(command);

        printf("\n");
    }

    return 0;
}
