#include "lists.h"

/**
 * dlistint_len - count the nbr of nodes in linked list
 * @h: ptr to beginning of linked list
 *
 * Return: nodes number
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t ix;

	for (ix = 0; h != NULL; ix++)
		h = h->next;
	return (ix);
}
