#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>

extern char **environ;

/* Function prototypes */
int execute_command(char **args);
int execute_builtin(char **args);
void print_prompt(void);
char *read_line(void);
char **tokenize_line(char *line);
void free_args(char **args);
void print_environment(void);
int _strcmp(const char *s1, const char *s2);
int is_builtin(char **args);

#endif /* HOLBERTON_H */
