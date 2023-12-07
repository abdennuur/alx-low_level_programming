#include "lists.h"

/**
 * get_dnodeint_at_index - find specific node of linked list
 * @head: ptr to beginning of list
 * @index: index of node to retrieve
 *
 * Return: ptr to indexed node, or NULL -> failure
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int ix;

	if (head == NULL)
		return (NULL);
	if (index == 0)
		return (head);
	for (ix = 0; ix < index; ix++)
	{
		if (head->next == NULL)
			return (NULL);
		head = head->next;
	}
	return (head);
}
