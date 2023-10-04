#include "shell.h"

/**
 * _calc_length - calc lenght
 * @x: number.
 * Return: Lenght
 */
int _calc_length(int x)
{
	unsigned int numm;
	int l = 1;

	if (x < 0)
	{
		l++;
		numm = x * -1;
	}
	else
	{
		numm = x;
	}
	while (numm > 9)
	{
		l++;
		numm = numm / 10;
	}

	return (l);
}
/**
 * _a_i - converts intger
 * @x: number
 * Return: String.
 */
char *_a_i(int x)
{
	unsigned int numm;
	int l = _calc_length(x);
	char *b;

	b = malloc(sizeof(char) * (l + 1));
	if (b == 0)
		return (NULL);

	*(b + l) = '\0';

	if (x < 0)
	{
		numm = x * -1;
		b[0] = '-';
	}
	else
	{
		numm = x;
	}

	l--;
	do {
		*(b + l) = (numm % 10) + '0';
		numm = numm / 10;
		l--;
	}
	while (numm > 0)
		;
	return (b);
}

/**
 * _at - converts a str
 * @c: string.
 * Return: int
 */
int _at(char *c)
{
	unsigned int a = 0, d = 0, e = 0, f = 1, g = 1, h;

	while (*(c + a) != '\0')
	{
		if (d > 0 && (*(c + a) < '0' || *(c + a) > '9'))
			break;

		if (*(c + a) == '-')
			f *= -1;

		if ((*(c + a) >= '0') && (*(c + a) <= '9'))
		{
			if (d > 0)
				g *= 10;
			d++;
		}
		a++;
	}

	for (h = a - d; h < a; h++)
	{
		e = e + ((*(c + h) - 48) * g);
		g /= 10;
	}
	return (e * f);
}
