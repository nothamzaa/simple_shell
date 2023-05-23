#ifndef SHELL_H
#define SHELL_H

/* Libraries */
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <stddef.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <stdbool.h>
#include <signal.h>

/* Macro */
#define BUFSIZE 1024

/* Structure */
typedef struct linked_list_s
{
    char *s;
    struct linked_list_s *next;
} linked_list_t;

/* Function prototypes */
int _putchar(char c);
void print_help(shell_t *shell, char *builtin);
void add_node_end(linked_list_t **head, char *s);
void free_list(linked_list_t *head);

#endif /* SHELL_H */
