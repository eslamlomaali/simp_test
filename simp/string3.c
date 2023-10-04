#include "shell.h"

/**
 * _revers_string - reverses a string.
 * @c: string.
 * Return: void.
 */
void _revers_string(char *c)
{
	int a = 0, b, d;
	char *e, f;

	while (a >= 0)
	{
		if (c[a] == '\0')
			break;
		a++;
	}
	e = c;

	for (b = 0; b < (a - 1); b++)
	{
		for (d = b + 1; d > 0; d--)
		{
			f = *(e + d);
			*(e + d) = *(e + (d - 1));
			*(e + (d - 1)) = f;
		}
	}
}
