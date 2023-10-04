#include "shell.h"

/**
 * node_to_end - put separator
 * @h: head
 * @s: separator
 * Return: address
 */
Linked_List *node_to_end(Linked_List **h, char s)
{
	Linked_List *a, *b;

	a = malloc(sizeof(Linked_List));
	if (a == NULL)
		return (NULL);

	a->space = s;
	a->access = NULL;
	b = *h;

	if (b == NULL)
	{
		*h = a;
	}
	else
	{
		while (b->access != NULL)
			b = b->access;
		b->access = a;
	}

	return (*h);
}

/**
 * ffree - free linked list
 * @h: head
 * Return: void
 */
void ffree(Linked_List **h)
{
	Linked_List *b;
	Linked_List *a;

	if (h != NULL)
	{
		a = *h;
		while ((b = a) != NULL)
		{
			a = a->access;
			free(b);
		}
		*h = NULL;
	}
}

/**
 * node_to_end_2 - puts cmd.
 * @h: head
 * @range: cmd L
 * Return: address
 */
Linked_List_2 *node_to_end_2(Linked_List_2 **h, char *range);
{
	Linked_List_2 *a, *b;

	a = malloc(sizeof(Linked_List_2));
	if (a == NULL)
		return (NULL);

	a->l = range;
	a->access = NULL;
	b = *h;

	if (b == NULL)
	{
		*h = a;
	}
	else
	{
		while (b->access != NULL)
			b = b->access;
		b->access = a;
	}

	return (*h);
}

/**
 * ffree_2 - free linked list
 * @h: head
 * Return: void.
 */
void ffree_2(Linked_List_2 **h)
{
	Linked_List_2 *b;
	Linked_List_2 *a;

	if (h != NULL)
	{
		a = *h;
		while ((b = a) != NULL)
		{
			a = a->access;
			free(b);
		}
		*h = NULL;
	}
}
