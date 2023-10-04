#include "shell.h"

/**
 * _sh_exit - exits the shell
 *
 * @hash: data
 * Return: 0 on success.
 */
int _sh_exit(main_data *hash)
{
	unsigned int usa;
	int num;
	int num2;
	int num3;

	if (hash->as[1] != NULL)
	{
		usa = _at(hash->as[1]);
		num = _dig(hash->as[1]);
		num2 = _string_length(hash->as[1]);
		num3 = usa > (unsigned int)INT_MAX;
		if (!num || num2 > 10 || num3)
		{
			_get_all_err(hash, 2);
			hash->sstt = 2;
			return (1);
		}
		hash->sstt = (usa % 256);
	}
	return (0);
}
