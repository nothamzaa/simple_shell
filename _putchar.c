#include "shell.h"

/**
 * _putchar - Prints a character
 * @c: Input character
 * Return: Returns 1 upon success
 */

int _putchar(char c)
{
    return (write(STDOUT_FILENO, &c, 1));
}
