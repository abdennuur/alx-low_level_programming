#include "lists.h"

/**
 * add_dnodeint - add new node at beginning of dlistint_t list
 * @head: double ptr to head of list
 * @n: added data
 *
 * Return: address of new element, or NULL -> failed
 */

dlistint_t *add_dnodeint(dlistint_t **head, const int n)
{
	dlistint_t *nd;

	nd = malloc(sizeof(dlistint_t));
	if (nd == NULL)
		return (NULL);

	nd->n = n;
	nd->next = *head;
	nd->prev = NULL;
	if (*head != NULL)
		(*head)->prev = nd;
	*head = nd;
	return (nd);
}
