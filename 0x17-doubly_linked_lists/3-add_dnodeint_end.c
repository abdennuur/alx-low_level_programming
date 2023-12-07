#include "lists.h"
#include <stdlib.h>

/**
 * add_dnodeint_end - add node to the end of linked list
 * @head: double ptr to beginning of linked list
 * @n: new node added value
 *
 * Return: ptr to new node, or NULL -> failure
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *nw, *temp;

	if (head == NULL)
		return (NULL);
	nw = malloc(sizeof(dlistint_t));
	if (nw == NULL)
		return (NULL);
	nw->n = n;
	nw->next = NULL;
	if (*head == NULL)
	{
		nw->prev = NULL;
		*head = nw;
		return (nw);
	}
	temp = *head;
	while (temp->next != NULL)
		temp = temp->next;
	temp->next = nw;
	nw->prev = temp;
	return (nw);
}
