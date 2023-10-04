#include "shell.h"

/**
 * _cd_5 - change dir
 *
 * @hash: data
 * Return: 1 on success
 */
int _cd_5(main_data *hash)
{
	char *directry;
	int h1, h2, h3;

	directry = hash->as[1];

	if (directry != NULL)
	{
		h1 = _string_compare("$HOME", directry);
		h2 = _string_compare("~", directry);
		h3 = _string_compare("--", directry);
	}

	if (directry == NULL || !h1 || !h2 || !h3)
	{
		_cd_4(hash);
		return (1);
	}

	if (_string_compare("-", directry) == 0)
	{
		_cd_3(hash);
		return (1);
	}

	if (_string_compare(".", directry) == 0 ||
			_string_compare("..", directry) == 0)
	{
		_cd_1(hash);
		return (1);
	}

	_cd_2(hash);

	return (1);
}
