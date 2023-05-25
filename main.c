#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "main.h"

void execute_command(char *command)
{
    printf("Executing command: %s\n", command);
    /* You can replace this with the actual execution logic
     * Here, we simply print the command that would have been executed
     */
}

int main(void)
{
    while (1)
    {
        /* Display the prompt */
        printf("$ ");
        fflush(stdout);

        /* Read the command from the user */
        char command[MAX_COMMAND_LENGTH];
        if (fgets(command, sizeof(command), stdin) == NULL)
        {
            /* Handle end of file condition (Ctrl+D) */
            printf("\n");
            break;
        }

        /* Remove the trailing newline character */
        command[strcspn(command, "\n")] = '\0';

        /* Check if the user wants to exit */
        if (strcmp(command, "exit") == 0)
        {
            break;
        }

        /* Execute the command */
        execute_command(command);
    }

    return 0;
}
