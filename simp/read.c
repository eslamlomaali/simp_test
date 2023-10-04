#include "shell.h"

/**
 * _read - read str
 * @x: val
 * Return: string
 */
char *_read(int *x)
{
	char *a = NULL;
	size_t b = 0;

	*x = _have(&a, &b, stdin);

	return (a);
}
