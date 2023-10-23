#include "lists.h"
#include <stdio.h>

/**
 * print_listint - to prints all the elements of a listint_t list.
 *
 * @h: a head of linklist node
 *
 * Return: the nbr of nodes
 *
 */
size_t print_listint(const listint_t *h)
{
	size_t cnt = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
		cnt++;
	}
	return (cnt);
}
