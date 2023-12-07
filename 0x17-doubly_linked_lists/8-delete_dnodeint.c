#include "lists.h"
#include <stdlib.h>

/**
 * delete_dnodeint_at_index - delete node at specific index
 * @head: double ptr to linked list
 * @index: index to delete node
 *
 * Return: 1 -> success, -1 -> failure
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *curr;
	unsigned int ix;

	if (head == NULL || *head == NULL)
		return (-1);
	curr = *head;
	if (index == 0)
	{
		*head = curr->next;
		if (curr->next != NULL)
		{
			curr->next->prev = NULL;
		}
		free(curr);
		return (1);
	}
	for (ix = 0; ix < index; ix++)
	{
		if (curr->next == NULL)
			return (-1);
		curr = curr->next;
	}
	curr->prev->next = curr->next;
	if (curr->next != NULL)
		curr->next->prev = curr->prev;
	free(curr);
	return (1);
}
