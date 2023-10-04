#include "shell.h"

/**
 * _string_duplicates - string duplicates
 * @c: string
 * Return: string
 */
char *_string_duplicates(const char *c)
{
	char *a;
	size_t b;

	b = _string_length(c);
	a = malloc(sizeof(char) * (b + 1));
	if (a == NULL)
		return (NULL);
	_copy_c(a, c, b + 1);
	return (a);
}

/**
 * _string_length - lenght of string.
 * @c: pointer
 * Return: Always 0.
 */
int _string_length(const char *c)
{
	int b;

	for (b = 0; c[b] != 0; b++)
	{
	}
	return (b);
}

/**
 * _charcters_compare - compare strings
 * @stringg: string
 * @c: cutter
 *
 * Return: 1 =, 0 if not.
 */
int _charcters_compare(char stringg[], const char *c)
{
	unsigned int x, y, z;

	for (x = 0, z = 0; stringg[x]; x++)
	{
		for (y = 0; c[y]; y++)
		{
			if (stringg[x] == c[y])
			{
				z++;
				break;
			}
		}
	}
	if (x == z)
		return (1);
	return (0);
}

/**
 * _string_toknaization -cut string
 * @stringg: string
 * @c: cutter
 *
 * Return: string
 */
char *_string_toknaization(char stringg[], const char *c)
{
	static char *cut, *s2;
	char *s1;
	unsigned int x, bool;

	if (stringg != NULL)
	{
		if (_charcters_compare(stringg, c))
			return (NULL);
		cut = stringg;
		x = _string_length(stringg);
		s2 = &stringg[x];
	}
	s1 = cut;
	if (s1 == s2)
		return (NULL);

	for (bool = 0; *cut; cut++)
	{

		if (cut != s1)
			if (*cut && *(cut - 1) == '\0')
				break;

		for (x = 0; c[x]; x++)
		{
			if (*cut == c[x])
			{
				*cut = '\0';
				if (cut == s1)
					s1++;
				break;
			}
		}
		if (bool == 0 && *cut)
			bool = 1;
	}
	if (bool == 0)
		return (NULL);
	return (s1);
}

/**
 * _dig - string is a number
 * @c: string
 * Return: 1 num , 0 not
 */
int _dig(const char *c)
{
	unsigned int x;

	for (x = 0; c[x]; x++)
	{
		if (c[x] < 48 || c[x] > 57)
			return (0);
	}
	return (1);
}
