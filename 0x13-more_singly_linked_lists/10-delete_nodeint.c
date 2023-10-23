#include "lists.h"
#include <stdlib.h>

/**
 * delete_nodeint_at_index - delete the node in the index
 * @head: double ptr
 * @index:  node index
 *
 * Return: ptr to the node index
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int j;
	listint_t *tmp, *nxt;

	if (head == NULL || *head == NULL)
		return (-1);
	if (index == 0)
	{
		nxt = (*head)->next;
		free(*head);
		*head = nxt;
		return (1);
	}
	tmp = *head;
	for (j = 0; j < index - 1; j++)
	{
		if (tmp->next == NULL)
			return (-1);
		tmp = tmp->next;
	}
	nxt = tmp->next;
	tmp->next = nxt->next;
	free(nxt);
	return (1);

}
