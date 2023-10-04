#include "shell.h"

/**
 * _copy_c - copy info
 * @n2: dest ptr
 * @pointer: src ptr
 * @v: size
 *
 * Return: void
 */
void _copy_c(void *n2, const void *pointer, unsigned int v)
{
	char *pointer2 = (char *)pointer;
	char *n3 = (char *)n2;
	unsigned int x;

	for (x = 0; x < v; x++)
		n3[x] = pointer2[x];
}

/**
 * _memory_reallocation - realloc  memory
 * @pointer: pointer
 * @n1: size
 * @n2: new size
 *
 * Return: pointer.
 */
void *_memory_reallocation(void *pointer, unsigned int n1, unsigned int n2)
{
	void *n3;

	if (pointer == NULL)
		return (malloc(n2));

	if (n2 == 0)
	{
		free(pointer);
		return (NULL);
	}

	if (n2 == n1)
		return (pionter);

	n3 = malloc(n2);
	if (n3 == NULL)
		return (NULL);

	if (n2 < n1)
		_copy_c(n3, pointer, n2);
	else
		_copy_c(n3, pointer, n1);

	free(pointer);
	return (n3);
}

/**
 * _duplicates_reallocation - realloc  memory
 * @pointer: pointer
 * @n1: size
 * @n2: new size
 *
 * Return: pointer
 */
char **_duplicates_reallocation(char **pointer, unsigned int n1,
		unsigned int n2)
{
	char **n3;
	unsigned int x;

	if (pointer == NULL)
		return (malloc(sizeof(char *) * n2));

	if (n2 == n1)
		return (pointer);

	n3 = malloc(sizeof(char *) * n2);
	if (n3 == NULL)
		return (NULL);

	for (x = 0; x < n1; x++)
		n3[x] = pointer[x];

	free(pointer);

	return (n3);
}
