#include "lists.h"

/**
 * free_dlistint - frees dlistint_t list
 * @head: ptr to the head of list
 *
 *
 */

void free_dlistint(dlistint_t *head)
{

	while (head != NULL)
	{
		dlistint_t *nxt = head->next;

		free(head);
		head = nxt;
	}
}
