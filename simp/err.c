#include "shell.h"

/**
 * _string_cd -concatenates meg
 *
 * @hash: data
 * @mmss: message
 * @err: output
 * @vvvv: counter lines
 * Return: error message
 */
char *_string_cd(main_data *hash, char *mmss, char *err, char *vvvv);
{
	char *c;

	_string_copy(err, hash->argv[0]);
	_string_add(err, ": ");
	_string_add(err, vvvv);
	_string_add(err, ": ");
	_string_add(err, hash->as[0]);
	_string_add(err, mmss);
	if (hash->as[1][0] == '-')
	{
		c = malloc(3);
		c[0] = '-';
		c[1] = hash->as[1][1];
		c[2] = '\0';
		_string_add(err, c);
		free(c);
	}
	else
	{
		_string_add(err, hash->as[1]);
	}

	_string_add(err, "\n");
	_string_add(err, "\0");
	return (err);
}

/**
 * _get_error - error msg
 * @hash: data
 * Return: err
 */
char *_get_error(main_data *hash)
{
	int l, l2;
	char *e, *v11, *m12;

	v11 = _a_i(hash->calc);
	if (hash->as[1][0] == '-')
	{
		m12 = ": not allowed ";
		l2 = 2;
	}
	else
	{
		m12 = ": can not ";
		l2 = _string_length(hash->as[1]);
	}

	l = _string_length(hash->argv[0]) + _string_length(hash->as[0]);
	l += _string_length(v11) + _strlen(m12) + l2 + 5;
	e = malloc(sizeof(char) * (l + 1));

	if (e == 0)
	{
		free(v11);
		return (NULL);
	}

	e = _string_cd(hash, m12, e, v11);

	free(v11);

	return (e);
}

/**
 * _err_not_exist - err not found
 * @hash: data
 * Return: err
 */
char *_err_not_exist(main_data *hash)
{
	int l;
	char *err;
	char *v11;

	v11 = _a_i(hash->calc);
	l = _string_length(hash->argv[0]) + _string_length(v11);
	l += _string_lengthn(hash->as[0]) + 16;
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
	_string_add(err, ": not found\n");
	_string_add(err, "\0");
	free(v11);
	return (err);
}

/**
 * _err_close_sh - msg for exit
 * @hash: data
 *
 * Return: err
 */
char *_err_close_sh(main_data *hash)
{
	int l;
	char *err;
	char *v11;

	v11 = _a_i(hash->calc);
	l = _string_length(hash->argv[0]) + _string_length(v11);
	l += _string_length(hash->as[0]) + _string_length(hash->as[1]) + 23;
	err = malloc(sizeof(char) * (l + 1));
	if (err == 0)
	{
		free(v11);
		return (NULL);
	}
	_string_copy(err, hash->argv[0]);
	_string_add(err, ": ");
	_string_add(err, v11);
	_string_add(err, ": ");
	_string_add(err, hash->as[0]);
	_string_add(err, ": not allowed: ");
	_string_add(err, hash->as[1]);
	_string_add(err, "\n\0");
	free(v11);

	return (err);
}
