#include "shell.h"

/* Function prototypes */
void shell_loop(void);

/* Global variable */
bool interactive_shell = true;

/* Main function */
int main(int argc, char **argv, char **env)
{
    (void)argc, (void)argv;
    if (!isatty(STDIN_FILENO))
        interactive_shell = false;

    /* Initialize signal handlers */
    signal(SIGINT, SIG_IGN);
    signal(SIGQUIT, SIG_IGN);
    signal(SIGTSTP, SIG_IGN);

    /* Call main shell loop */
    shell_loop();

    /* Free environment variable */
    if (env)
    {
        char **temp = env;

        while (*env)
            free(*env++);
        free(temp);
    }
    return (EXIT_SUCCESS);
}

/* Shell loop function */
void shell_loop(void)
{
    char *line = NULL; /* line read */
    char **args = NULL; /* tokens */
    ssize_t bytes_read = 0; /* read line */
    size_t size = 0; /* read line */
    int status = 0; /* exit status code */

    do {
        /* Print prompt */
        if (interactive_shell)
            _putchar('$');

        /* Read user input */
        bytes_read = getline(&line, &size, stdin);

        /* Handle EOF */
        if (bytes_read == -1)
        {
            if (interactive_shell)
                _putchar('\n');
            break;
        }

        /* Remove trailing newline */
        if (line[bytes_read - 1] == '\n')
            line[bytes_read - 1] = '\0';

        /* Split line into arguments */
        args = split_line(line);

        /* Execute command */
        status = execute(args);

        /* Free memory */
        free(line);
        free(args);
    } while (status);
}

/* Other functions left as an exercise */
