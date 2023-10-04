#include "shell.h"

/**
 * _cp_inf- copy information
 * @nn: name
 * @val: value
 *
 * Return: new env
 */
char *_cp_inf(char *nn, char *val)
	char *x;
	int y, z, a;

	y = _string_length(nn);
	z = _string_length(val);
	a = y + z + 2;
	x = malloc(sizeof(char) * (a));
	_string_copy(x, nn);
	_string_add(x, "=");
	_string_add(x, val);
	_string_add(x, "\0");

	return (x);
}

/**
 * _setup_env - setup an environment
 *
 * @nn: name
 * @val: value
 * @hash: data
 * Return: void
 */
void _setup_env(char *nn, char *val, main_data *hash)
{
	int i;
	char *varrr, *dodo;

	for (i = 0; hash->_environment[i]; i++)
	{
		varrr = _string_duplicates(hash->_environment[i]);
		dodo = _string_toknaization(varrr, "=");
		if (_string_compare(dodo, nn) == 0)
		{
			free(hash->_environment[i]);
			hash->_environment[i] = _cp_inf(dodo, val);
			free(varrr);
			return;
		}
		free(varrr);
	}

	hash->_environment = _duplicates_reallocation(hash->_environment, i, sizeof
	(char *) * (i + 2));
	hash->_environment[i] = _cp_inf(nn, val);
	hash->_environment[i + 1] = NULL;
}

/**
 * _ready_env - compares env
 * @hash: data
 *
 * Return: 1 on success.
 */
int _ready_env(main_data *hash)
{

	if (hash->as[1] == NULL || hash->as[2] == NULL)
	{
		_get_all_err(hash, -1);
		return (1);
	}

	_setup_env(hash->as[1], hash->as[2], hash);

	return (1);
}

/**
 * _not_ready_env - remove a environment
 *
 * @hash: data
 *
 * Return: 1 on success.
 */
int _not_ready_env(main_data *hash)
{
	char **aaaaa;
	char *vvv, *eee;
	int o, b, c;

	if (hash->as[1] == NULL)
	{
		_get_all_err(hash, -1);
		return (1);
	}
	c = -1;
	for (o = 0; hash->_environment[o]; o++)
	{
		vvv = _string_duplicates(hash->_environment[o]);
		eee = _string_toknaization(vvv, "=");
		if (_string_compare(eee, hash->as[1]) == 0)
		{
			c = o;
		}
		free(vvv);
	}
	if (c == -1)
	{
		_get_all_err(hash, -1);
		return (1);
	}
	aaaaa = malloc(sizeof(char *) * (o));
	for (o = b = 0; hash->_environment[o]; o++)
	{
		if (o != c)
		{
			aaaaa[b] = hash->_environment[o];
			b++;
		}
	}
	aaaaa[b] = NULL;
	free(hash->_environment[c]);
	free(hash->_environment);
	hash->_environment = aaaaa;
	return (1);
}
