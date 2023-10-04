#include "shell.h"

/**
 * _no_comm - remove comments
 *
 * @c: string
 * Return: string
 */
char *_no_comm(char *c)
{
	int y, z;

	z = 0;
	for (y = 0; c[y]; y++)
	{
		if (c[y] == '#')
		{
			if (y == 0)
			{
				free(c);
				return (NULL);
			}

			if (c[y - 1] == ' ' || c[y - 1] == '\t' || c[y - 1] == ';')
				z = y;
		}
	}

	if (z != 0)
	{
		c = _memory_reallocation(c, y, z + 1);
		c[z] = '\0';
	}

	return (c);
}

/**
 * _loop - Loop
 * @hash: data
 *
 * Return: void
 */
void _loop(main_data *hash)
{
	int x, y;
	char *z;

	x = 1;
	while (x == 1)
	{
		write(STDIN_FILENO, "^-^ ", 4);
		z = _read(&y);
		if (y != -1)
		{
			z = _no_comm(z);
			if (z == NULL)
				continue;

			if (_check_err(hash, z) == 1)
			{
				hash->sstt = 2;
				free(z);
				continue;
			}
			z = _rep_2(z, hash);
			x = _cut_cmd(hash, z);
			hash->calc += 1;
			free(z);
		}
		else
		{
			x = 0;
			free(z);
		}
	}
}
