#include "lists.h"
#include <stdio.h>

/**
 * print_dlistint - prints all elements of dlistint_t list
 * @h: ptr to start of linked list
 *
 * Return: nodes number
 */
size_t print_dlistint(const dlistint_t *h)
{
	size_t ix;

	for (ix = 0; h != NULL; ix++)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
	return (ix);
}
