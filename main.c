/**
 * _strdup - Duplicates a string
 * @str: The string to duplicate
 *
 * Return: The pointer to the duplicated string
 */
char *_strdup(const char *str)
{
	char *dup;
	int length = 0, i;

	if (str == NULL)
		return (NULL);

	while (str[length])
		length++;

	dup = malloc(sizeof(char) * (length + 1));
	if (dup == NULL)
		return (NULL);

	for (i = 0; i <= length; i++)
		dup[i] = str[i];

	return (dup);
}

/**
 * print_array - Prints an array of integers
 * @array: The array to print
 * @size: The size of the array
 */
void print_array(const int *array, size_t size)
{
	size_t i;

	if (array == NULL || size == 0)
		return;

	for (i = 0; i < size; i++)
	{
		printf("%d", array[i]);
		if (i < size - 1)
			printf(", ");
	}
	printf("\n");
}

/**
 * swap_int - Swaps the values of two integers
 * @a: The first integer
 * @b: The second integer
 */
void swap_int(int *a, int *b)
{
	int temp;

	if (a == NULL || b == NULL)
		return;

	temp = *a;
	*a = *b;
	*b = temp;
}

/**
 * main - Entry point
 *
 * Return: Always 0
 */
int main(void)
{
	int array[] = {5, 2, 4, 3, 1};
	size_t size = sizeof(array) / sizeof(array[0]);
	int i, j;

	for (i = 0; i < size - 1; i++)
	{
		for (j = 0; j < size - i - 1; j++)
		{
			if (array[j] > array[j + 1])
			{
				swap_int(&array[j], &array[j + 1]);
			}
		}
	}

	print_array(array, size);

	return (0);
}
