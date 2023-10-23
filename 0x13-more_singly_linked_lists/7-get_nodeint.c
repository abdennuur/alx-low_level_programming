#include "lists.h"

/**
 * get_nodeint_at_index - return nth node of listint_t linked list.
 * @head: ptr to the first node
 * @index: the index of the node
 *
 * Return: ptr of index
 */
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)
{
	unsigned int j;

	if (head == NULL)
		return (NULL);
	for (j = 0; j < index; j++)
	{
		head = head->next;
		if (head == NULL)
			return (NULL);
	}
	return (head);
}
