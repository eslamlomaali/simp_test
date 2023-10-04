#include "shell.h"

/**
 * _char_subs - swaps chars
 *
 * @c: string
 * @bool: type
 * Return: string
 */
char *_char_subs(char *c, int bool)
{
	int x;

	if (bool == 0)
	{
		for (x = 0; c[x]; x++)
		{
			if (c[x] == '|')
			{
				if (c[x + 1] != '|')
					c[x] = 16;
				else
					x++;
			}

			if (c[x] == '&')
			{
				if (c[x + 1] != '&')
					c[x] = 12;
				else
					x++;
			}
		}
	}
	else
	{
		for (x = 0; c[x]; x++)
		{
			c[x] = (c[x] == 16 ? '|' : c[x]);
			c[x] = (c[x] == 12 ? '&' : c[x]);
		}
	}
	return (c);
}

/**
 * _add - add spaces
 *
 * @h1: head
 * @h2: head
 * @c: string
 * Return: void
 */
void _add(Linked_List **h1, Linked_List_2 **h2, char *c)
{
	int x;
	char *y;

	c = _char_subs(c, 0);

	for (x = 0; c[x]; x++)
	{
		if (c[x] == ';')
			node_to_end(h1, c[x]);

		if (c[x] == '|' || c[x] == '&')
		{
			node_to_end(h1, c[x]);
			x++;
		}
	}

	y = _string_toknaization(c, ";|&");
	do {
		y = _char_subs(y, 1);
		node_to_end_2(h2, y);
		y = _string_toknaization(NULL, ";|&");
	} while (y != NULL);

}

/**
 * _by - go for cmd l
 *
 * @l1: list
 * @l2: list
 * @hash: data
 * Return: void
 */
void _by(Linked_List **l1, Linked_List_2 **l2, main_data *hash)
{
	int vamos;
	Linked_List *x;
	Linked_List_2 *y;

	vamos = 1;
	x = *l1;
	y = *l2;

	while (x != NULL && vamos)
	{
		if (hash->sstt == 0)
		{
			if (x->space == '&' || x->space == ';')
				vamos = 0;
			if (x->space == '|')
				y = y->access, x = x->access;
		}
		else
		{
			if (x->space == '|' || x->space == ';')
				vamos = 0;
			if (x->space == '&')
				y = y->access, x = x->access;
		}
		if (x != NULL && !vamos)
			x = x->access;
	}

	*l1 = x;
	*l2 = y;
}

/**
 * _cut_cmd - cut cmd l
 *
 * @hash: data
 * @c: string
 * Return: 0 to close, 1 to more
 */
int _cut_cmd(main_data *hash, char *c)
{

	Linked_List *h1, *l1;
	Linked_List_2 *h2, *l2;
	int r;

	h1 = NULL;
	h2 = NULL;

	_add(&h1, &h2, c);

	l1 = h1;
	l2 = h2;

	while (l2 != NULL)
	{
		hash->enter = l2->l;
		hash->as = _cut(hash->enter);
		r = _exe(hash);
		free(hash->as);

		if (r == 0)
			break;

		_by(&l1, &l2, hash);

		if (l2 != NULL)
			l2 = l2->access;
	}

	ffree(&h1);
	ffree_2(&h2);

	if (r == 0)
		return (0);
	return (1);
}

/**
 * _cut - cut string
 *
 * @c: string.
 * Return: string
 */
char **_cut(char *c)
{
	size_t a;
	size_t b;
	char **d;
	char *e;

	a = TOK_BUFSIZE;
	d = malloc(sizeof(char *) * (a));
	if (d == NULL)
	{
		write(STDERR_FILENO, ": err\n", 18);
		exit(EXIT_FAILURE);
	}

	e = _string_toknaization(c, TOK_DELIM);
	d[0] = e;

	for (b = 1; e != NULL; b++)
	{
		if (b == a)
		{
			a += TOK_BUFSIZE;
			d = _duplicates_reallocation(d, b, sizeof(char *) * a);
			if (d == NULL)
			{
				write(STDERR_FILENO, ": err\n", 18);
				exit(EXIT_FAILURE);
			}
		}
		e = _string_toknaization(NULL, TOK_DELIM);
		d[b] = e;
	}

	return (d);
}
