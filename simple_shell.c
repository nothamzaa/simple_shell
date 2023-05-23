#include "header_file.h"

/**
 * main - Entry point for the shell program
 *
 * Return: Exit status
 */
int main(void)
{
    char *input;
    char **args;
    int status;

    do {
        display_prompt();  // Display the prompt
        input = read_input();  // Read user input

        if (input != NULL) {
            args = parse_input(input);  // Parse the input into tokens
            if (args != NULL) {
                status = execute_command(args);  // Execute the command

                free(args);
            } else {
                status = 1;  // Invalid input, continue to next iteration
            }

            free(input);
        } else {
            status = 0;  // Exit the shell on end of file condition (Ctrl+D)
        }
    }
