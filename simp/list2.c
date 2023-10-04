#include "shell.h"

/**
 * add_node - puts var
 * @h: head
 * @eslam: length
 * @ashraf: value
 * @ali: length
 * Return: address
 */
Linked_List_3 *add_node(Linked_List_3 **h, int eslam, char *ashraf, int ali)
{
	Linked_List_3 *a, *b;

	a = malloc(sizeof(Linked_List_3));
	if (a == NULL)
		return (NULL);

	a->length_variable = eslam;
	a->vv = ashraf;
	a->length_value = ali;
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
 * ffree_3 - free linked list
 * @h: head
 * Return: void
 */
void ffree_3(Linked_List_3 **h)
{
	Linked_List_3 *b;
	Linked_List_3 *a;

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
