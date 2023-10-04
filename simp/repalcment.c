#include "shell.h"

/**
 * _check - check env
 *
 * @h: head
 * @c: string
 * @main: data
 * Return: void
 */
void _check(Linked_List_3 **h, char *c, main_data *main)

	int a, b, d, e;
	char **_f;

	_f = main->_environment;
	for (a = 0; _f[a]; a++)
	{
		for (d = 1, b = 0; _f[a][b]; b++)
		{
			if (_f[a][b] == '=')
			{
				e = _string_length(_f[a] + b + 1);
				add_node(h, d, _f[a] + b + 1, e);
				return;
			}

			if (c[d] == _f[a][b])
				d++;
			else
				break;
		}
	}

	for (d = 0; c[d]; d++)
	{
		if (c[d] == ' ' || c[d] == '\t' || c[d] == ';' || c[d] == '\n')
			break;
	}

	add_node(h, d, NULL, 0);
}

/**
 * _check_2 - check var
 *
 * @h: head
 * @c: string
 * @e: status
 * @main: data
 * Return: void
 */
int _check_2(Linked_List_3 **h, char *c, char *e, main_data *main)
{
	int xx, yy, zz;

	yy = _string_length(e);
	zz = _string_length(main->process);

	for (xx = 0; c[xx]; xx++)
	{
		if (c[xx] == '$')
		{
			if (c[xx + 1] == '?')
				add_node(h, 2, e, yy), xx++;
			else if (c[xx + 1] == '$')
				add_node(h, 2, main->process, zz), xx++;
			else if (c[xx + 1] == '\n')
				add_node(h, 0, NULL, 0);
			else if (c[xx + 1] == '\0')
				add_node(h, 0, NULL, 0);
			else if (c[xx + 1] == ' ')
				add_node(h, 0, NULL, 0);
			else if (c[xx + 1] == '\t')
				add_node(h, 0, NULL, 0);
			else if (c[xx + 1] == ';')
				add_node(h, 0, NULL, 0);
			else
				_check(h, c + xx, main);
		}
	}

	return (xx);
}

/**
 * _rep - replace str
 * @h: head
 * @c: string
 * @e: string
 * @l: length
 * Return: string
 */
char *_rep(Linked_List_3 **h, char *c, char *e, int l)
{
	Linked_List_3 *w;
	int x, y, z;

	w = *h;
	for (y = x = 0; x < l; x++)
	{
		if (c[y] == '$')
		{
			if (!(w->length_variable) && !(w->length_value))
			{
				e[x] = c[y];
				y++;
			}
			else if (w->length_variable && !(w->length_value))
			{
				for (z = 0; z < w->length_variable; z++)
					y++;
				x--;
			}
			else
			{
				for (z = 0; z < w->length_value; z++)
				{
					e[x] = w->vv[z];
					x++;
				}
				y += (w->length_variable);
				x--;
			}
			w = w->access;
		}
		else
		{
			e[x] = c[y];
			y++;
		}
	}

	return (e);
}

/**
 * _rep_2 - replace vars
 *
 * @c: string
 * @hash: data
 * Return: string
 */
char *_rep_2(char *c, main_data *hash)
{
	Linked_List_3 *aa, *bb;
	char *dd, *ee;
	int ff, gg;

	dd = _a_i(hash->sstt);
	aa = NULL;

	ff = _check_2(&aa, c, dd, hash);

	if (aa == NULL)
	{
		free(dd);
		return (c);
	}

	bb = aa;
	gg = 0;

	while (bb != NULL)
	{
		gg += (bb->length_value - bb->length_variable);
		bb = bb->access;
	}

	gg += ff;

	ee = malloc(sizeof(char) * (gg + 1));
	ee[gg] = '\0';

	ee = _rep(&aa, c, ee, gg);

	free(c);
	free(dd);
	ffree_3(&aa);

	return (ee);
}
