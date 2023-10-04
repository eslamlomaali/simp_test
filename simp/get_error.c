#include "shell.h"

/**
 * _get_all_err - get error
 * @hash: data
 * @e: error
 * Return: error
 */
int _get_all_err(main_data *hash, int e)
{
	char *eerr;

	switch (e)
	{
	case -1:
		eerr = _err_env(hash);
		break;
	case 126:
		eerr = _err_p(hash);
		break;
	case 127:
		eerr = _err_not_exist(hash);
		break;
	case 2:
		if (_string_compare("exit", hash->as[0]) == 0)
			eerr = _err_close_sh(hash);
		else if (_string_compare("cd", hash->as[0]) == 0)
			eerr = _get_error(hash);
		break;
	}

	if (eerr)
	{
		write(STDERR_FILENO, eerr, _string_length(eerr));
		free(eerr);
	}

	hash->sstt = e;
	return (e);
}
