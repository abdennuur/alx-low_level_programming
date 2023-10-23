#include "lists.h"

/**
 * listint_len - the nbr of elements in linked listint_t list.
 *
 * @h: head ptr
 *
 * Return: the nbr of elements
 *
 */

size_t listint_len(const listint_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
	h = h->next;
		cnt++;
	}
	return (cnt);
}
