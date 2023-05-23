#ifndef _MINISHELL_H_
#define _MINISHELL_H_

#include <stddef.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>

#include "typedefs.h"

/* global program name */
extern char *name;

/* signals and processes */
void signal_handler(int fildes);

/* helpers for user inputs */
char *get_user_input(void);

/* helpers errors handling */
void readline_error(void);

#endif /* _MINISHELL_H_ */
