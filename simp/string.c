#include "shell.h"

/**
 * *_string_add - 2strings
 * @d: destination
 * @s: source
 * Return: destination
 */
char *_string_add(char *d, const char *s)
{
	int x;
	int z;

	for (x = 0; d[x] != '\0'; x++)
		;

	for (z = 0; s[z] != '\0'; z++)
	{
		d[x] = s[z];
		x++;
	}

	d[x] = '\0';
	return (d);
}
/**
 * *_string_copy - Copy string
 * @d: destination
 * @s: source
 * Return: destination
 */
char *_string_copy(char *d, char *s)
{

	size_t y;

	for (y = 0; s[y] != '\0'; y++)
	{
		d[y] = s[y];
	}
	d[y] = '\0';

	return (d);
}
/**
 * _string_compare - compares  strings.
 * @string1: string
 * @string2: string
 * Return: Always 0.
 */
int _string_compare(char *string1, char *string2)
{
	int a;

	for (a = 0; string1[a] == string2[a] && string1[a]; a++)
		;

	if (string1[a] > string2[a])
		return (1);
	if (string1[a] < string2[a])
		return (-1);
	return (0);
}
/**
 * *_string_charcter - where the char in the string
 * @a: string
 * @b: char
 * Return: pointer
 */
char *_string_charcter(char *a, char b)
{
	unsigned int x = 0;

	for (; *(a + x) != '\0'; x++)
		if (*(a + x) == b)
			return (a + x);
	if (*(a + x) == b)
		return (a + x);
	return ('\0');
}
/**
 * _string_s - calc length
 * @a: start
 * @b: bytes
 * Return: number
 */
int _string_s(char *a, char *b)
{
	int m, n, bool;

	for (m = 0; *(a + m) != '\0'; m++)
	{
		bool = 1;
		for (n = 0; *(b + n) != '\0'; n++)
		{
			if (*(a + m) == *(b + n))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (m);
}
