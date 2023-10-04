#include "shell.h"

/**
 * _come - set line
 * @lp: Buffer
 * @buf: string
 * @a: size
 * @z: size
 */
void _come(char **lp, size_t *a, char *buf, size_t z)
{

	if (*lp == NULL)
	{
		if  (z > BUFSIZE)
			*a = z;

		else
			*a = BUFSIZE;
		*lp = buf;
	}
	else if (*a < z)
	{
		if (z > BUFSIZE)
			*a = z;
		else
			*a = BUFSIZE;
		*lp = buf;
	}
	else
	{
		_string_copy(*lp, buf);
		free(buf);
	}
}
/**
 * _have - Read input
 * @lp: buffer
 * @a: size
 * @f: reader
 * Return: num
 */
ssize_t _have(char **lp, size_t *a, FILE *f)
{
	int i;
	static ssize_t x;
	ssize_t y;
	char *b;
	char d = 'z';

	if (x == 0)
		fflush(f);
	else
		return (-1);
	x = 0;

	b = malloc(sizeof(char) * BUFSIZE);
	if (b == 0)
		return (-1);
	while (d != '\n')
	{
		i = read(STDIN_FILENO, &d, 1);
		if (i == -1 || (i == 0 && x == 0))
		{
			free(b);
			return (-1);
		}
		if (i == 0 && x != 0)
		{
			x++;
			break;
		}
		if (x >= BUFSIZE)
			b = _memory_reallocation(b, x, x + 1);
		b[x] = d;
		x++;
	}
	b[x] = '\0';
	_come(lp, a, b, x);
	y = x;
	if (i != 0)
		x = 0;
	return (y);
}
