#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

/* Function Declarations */
int execute_command(char **args);
int is_builtin(char **args);
int _strcmp(const char *s1, const char *s2);
void print_environment(void);
char **tokenize_line(char *line);
void free_args(char **args);

#endif /* SHELL_H */
