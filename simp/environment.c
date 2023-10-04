#include "shell.h"

/**
 * is_equal- comp names
 * @n1: n2 of the environment variable
 * @n2: names passed
 *
 * Return: 1 =, 0 not
 */
int is_equal(const char *n1, const char *n2)
{
	int x;

	for (x = 0; n1[x] != '='; x++)
	{
		if (n1[x] != n2[x])
		{
			return (0);
		}
	}

	return (x + 1);
}

/**
 * _have_env - env var
 * @nn: name
 * @_env: environment variable
 *
 * Return: value of the env
 */
char *_have_env(const char *nn, char **_env)
{
	char *pointer;
	int x, y;

	pointer = NULL;
	y = 0;
	for (x = 0; _env[x]; x++)
	{
		y = is_equal(_env[x], nn);
		if (y)
		{
			pointer = _env[x];
			break;
		}
	}

	return (pointer + y);
}

/**
 * _environment_env - prints the environment var
 *
 * @hash: data
 * Return: 1 on success.
 */
int _environment_env(main_data *hash)
{
	int x, z;

	for (x = 0; hash->_environment[x]; x++)
	{

		for (z = 0; hash->_environment[x][z]; z++)
			;

		write(STDOUT_FILENO, hash->_environment[x], z);
		write(STDOUT_FILENO, "\n", 1);
	}
	hash->sstt = 0;

	return (1);
}
