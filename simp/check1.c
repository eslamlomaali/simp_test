#include "shell.h"

/**
 * _char_rep - counts the repetitions of a char
 *
 * @c: string
 * @x: index
 * Return: repet
 */
int _char_rep(char *c, int x)
{
	if (*(c - 1) == *c)
		return (_char_rep(c - 1, x + 1));

	return (x);
}

/**
 * _find_err - find errors
 *
 * @c: string
 * @x: index
 * @y: char
 * Return: index
 */
int _find_err(char *c, int x, char y)
{
	int a;

	a = 0;
	if (*c == '\0')
		return (0);

	if (*c == ' ' || *c == '\t')
		return (_find_err(c + 1, x + 1, y));

	if (*c == ';')
		if (y == '|' || y == '&' || y == ';')
		return (x);

	if (*c == '|')
	{
		if (y == ';' || y == '&')
			return (x);

		if (y == '|')
		{
			a = _char_rep(c, 0);
			if (a == 0 || a > 1)
				return (x);
		}
	}

	if (*c == '&')
	{
		if (y == ';' || y == '|')
			return (x);

		if (y == '&')
		{
			a = _char_rep(c, 0);
			if (a == 0 || a > 1)
			return (x);
		}
	}

	return (_find_err(c + 1, x + 1, *c));
}

/**
 * _index_of_char - index of char
 *
 * @c: string
 * @x: index
 * * Return: 1 error. 0 no
 */
int _index_of_char(char *c, int *x)
{

	for (*x = 0; c[*x]; *x += 1)
	{
		if (c[*x] == ' ' || c[*x] == '\t')
			continue;

		if (c[*x] == ';' || c[*x] == '|' || c[*x] == '&')
			return (-1);

		break;
	}

	return (0);
}

/**
 * _p_err - prints err
 *
 * @hash: data
 * @c: string
 * @x: index
 * @bool: error
 * Return: void
 */
void _p_err(main_data *hash, char *c, int x, int bool)
{
	char *m, *m_2, *m_3, *b, *a;
	int l;

	if (c[x] == ';')
	{
		if (bool == 0)
			m = (c[x + 1] == ';' ? ";;" : ";");
		else
			m = (c[x - 1] == ';' ? ";;" : ";");
	}

	if (c[x] == '|')
		m = (c[x + 1] == '|' ? "||" : "|");

	if (c[x] == '&')
		m = (c[x + 1] == '&' ? "&&" : "&");

	m_2 = ": err: \"";
	m_3 = "\" unexpected\n";
	a = _a_i(hash->calc);
	l = _string_length(hash->argv[0]) + _string_length(a);
	l += _string_length(m) + _string_length(m_2) + _string_length(m_3) + 2;

	b = malloc(sizeof(char) * (l + 1));
	if (b == 0)
	{
		free(a);
		return;
	}
	_string_copy(b, hash->argv[0]);
	_string_add(b, ": ");
	_string_add(b, a);
	_string_add(b, m_2);
	_string_add(b, m);
	_string_add(b, m_3);
	_string_add(b, "\0");

	write(STDERR_FILENO, b, l);
	free(b);
	free(a);
}

/**
 * _check_err - find & print err
 *
 * @hash: data
 * @c: string
 * Return: 1 error. 0 no
 */
int _check_err(main_data *hash, char *c)
{
	int a = 0;
	int z = 0;
	int x = 0;

	z = _index_of_char(c, &a);
	if (z == -1)
	{
		_p_err(hash, c, a, 0);
		return (1);
	}

	i = _find_err(c + a, 0, *(c + a));
	if (x != 0)
	{
	_p_err(hash, c, a + x, 1);
	return (1);
	}

	return (0);
