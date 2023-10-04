#include "shell.h"

/**
 * _exe - find cmd
 *
 * @hash: data
 * Return: 1 on success.
 */
int _exe(main_data *hash)
{
	int (*builtin)(main_data *hash);

	if (hash->as[0] == NULL)
		return (1);

	builtin = _have_b(hash->as[0]);

	if (builtin != NULL)
		return (builtin(hash));

	return (_executable(hash));
}
