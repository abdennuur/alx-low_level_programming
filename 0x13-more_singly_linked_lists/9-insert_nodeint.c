#include "lists.h"
#include <stdlib.h>

/**
 * insert_nodeint_at_index - insert a new node in agiven postion
 * @head: double ptr
 * @idx: index of node
 * @n: a new node value
 *
 * Return:  address of new node
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	unsigned int j;
	listint_t *tmp, *nw;

	if (head == NULL)
		return (NULL);
	if (idx != 0)
	{
		tmp = *head;
		for (j = 0; j < idx - 1 && tmp != NULL; j++)
		{
			tmp = tmp->next;
		}
		if (tmp == NULL)
			return (NULL);
	}
	nw = malloc(sizeof(listint_t));
	if (nw == NULL)
		return (NULL);
	nw->n = n;
	if (idx == 0)
	{
		nw->next = *head;
		*head = nw;
		return (nw);
	}
	nw->next = tmp->next;
	tmp->next = nw;
	return (nw);
}
