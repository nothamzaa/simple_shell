#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/* Function Prototypes */
char *read_command(void);
void execute_command(char *command);

#endif /* SHELL_H */
