#include "lists.h"
#include <stdlib.h>

/**
 * free_listint - free is a listint_t list
 *
 * @head: the head of list
 *
 * Return: NULL if it error
 */

void free_listint(listint_t *head)
{
	listint_t *nt;

	while (head != NULL)
	{
		nt = head->next;
		free(head);
		head = nt;
	}
}
