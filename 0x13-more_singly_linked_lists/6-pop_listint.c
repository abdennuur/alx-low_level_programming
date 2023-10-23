#include "lists.h"
#include <stdlib.h>

/**
 * pop_listint - deletes the head node
 * @head: a double ptr
 *
 *Return: (empty)
 */
int pop_listint(listint_t **head)
{
	listint_t *beg;
	int j;

	if (head == NULL || *head == NULL)
		return (0);
	beg = *head;
	*head = beg->next;
	j = beg->n;
	free(beg);
	return (j);
}
