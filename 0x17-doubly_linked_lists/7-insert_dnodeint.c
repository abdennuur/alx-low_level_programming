#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * insert_dnodeint_at_index - insert new node at given position
 * @h: double ptr to the beginning of linked list
 * @idx: index at which to insert new node
 * @n: data to be enter into new node
 *
 * Return: ptr to new node, or NULL -> failure
 */
dlistint_t *insert_dnodeint_at_index(dlistint_t **h, unsigned int idx, int n)
{
	dlistint_t *nw, *nxt, *curr;
	unsigned int ix;

	if (h == NULL)
		return (NULL);
	if (idx != 0)
	{
		curr = *h;
		for (ix = 0; ix < idx - 1 && curr != NULL; ix++)
			curr = curr->next;
		if (curr == NULL)
			return (NULL);
	}
	nw = malloc(sizeof(dlistint_t));
	if (nw == NULL)
		return (NULL);
	nw->n = n;
	if (idx == 0)
	{
		nxt = *h;
		*h = nw;
		nw->prev = NULL;
	}
	else
	{
		nw->prev = curr;
		nxt = curr->next;
		curr->next = nw;
	}
	nw->next = nxt;
	if (nw->next != NULL)
		nw->next->prev = nw;
	return (nw);
}
