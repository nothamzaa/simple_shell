#include "header.h"
/**
 * _reallocates -  reallocates the memory block using the malloc and free
 *@ptr: pointer
 *@old_size: previous Size Of The Pointer
 *@new_size: new size of the pointer
 *Return: Pointer to reallocated memory
 */
void *_reallocates(void *ptr, unsigned int old_size, unsigned int new_size)
{
	void *result;

	if (new_size == old_size)
		return (ptr);
	if (new_size == 0 && ptr)
	{
		free(ptr);
		return (NULL);
	}
	result = malloc(new_size);
	if (result == NULL)
	{
		free(result);
		return (NULL);
	}
	if (ptr == NULL)
	{
		fi_an_array(result, '\0', new_size);
		free(ptr);
	}
	else
	{
		_memocpy(result, ptr, old_size);
		free(ptr);
	}
	return (result);
}
/**
 * free_all - free all memory allocated
 * @cmd: array pointer
 * @line: char pointer
 * Return: Void
 */
void free_all(char **cmd, char *line)
{
	free(cmd);
	free(line);
	cmd = NULL;
	line = NULL;
}
/**
 * _memocpy - copy the bytes of memory from source to the destination
 *@dest: destination pointer
 *@src: source pointer
 *@n: size to be copied
 *Return: pointer to destination
 */
char *_memocpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;

	for (i = 0; i < n; i++)
	{
		dest[i] = src[i];
	}
	return (dest);
}
/**
 * fi_an_array - fill an array by the constant byte
 *@a: void pointer
 *@el: int
 *@len: length for int
 *Return: void pointer
 */
void *fi_an_array(void *a, int el, unsigned int len)
{
	char *p = a;
	unsigned int i = 0;

	while (i < len)
	{
		*p = el;
		p++;
		i++;
	}
	return (a);
}
/**
 * _callocates - allocates the memory for the array using malloc
 *@size: size
 *Return: void pointer
 */
void *_callocates(unsigned int size)
{
	char *a;
	unsigned int i;

	if (size == 0)
	return (NULL);
	a = malloc(size);
	if (a == NULL)
	return (NULL);
	for (i = 0; i < size; i++)
	{
		a[i] = '\0';
	}
	return (a);
}
