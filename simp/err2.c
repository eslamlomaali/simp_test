#include "shell.h"

/**
 * _err_env - error message
 * @hash: data relevant
 * Return: error
 */
char *_err_env(main_data *hash)
	int l;
	char *err;
	char *v11;
	char *m12;

	v11 = _a_i(hash->calc);
	m12 = ": can not add or rem\n";
	l = _string_length(hash->argv[0]) + _string_length(v11);
	l += _string_length(hash->as[0]) + _string_length(m12) + 4;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(err);
		free(v11);
		return (NULL);
	}

	_string_copy(err, hash->argv[0]);
	_string_add(err, ": ");
	_string_add(err, v11);
	_string_add(err, ": ");
	_string_add(err, hash->as[0]);
	_string_add(err, m12);
	_string_add(err, "\0");
	free(v11);

	return (err);
}
/**
 * _err_p - error message
 * @datash: data
 *
 * Return: error
 */
char *_err_p(main_data *hash)
{
	int l;
	char *v11;
	char *err;

	v11 = _a_i(hash->calc);
	l = _string_length(hash->argv[0]) + _string_length(v11);
	length += _string_length(hash->as[0]) + 24;
	error = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(err);
		free(v11);
		return (NULL);
	}
	_string_copy(err, hash->argv[0]);
	_string_add(err, ": ");
	_string_add(err, v11);
	_string_add(err, ": ");
	_string_add(err, hash->as[0]);
	_string_add(err, ": rejected\n");
	_string_add(err, "\0");
	free(v11);
	return (err);
}
