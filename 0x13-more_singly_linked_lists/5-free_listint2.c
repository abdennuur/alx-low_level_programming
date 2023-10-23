#include "lists.h"
#include <stdlib.h>

/**
 * free_listint2 - function free s a listint_t list
 * @head: a double ptr of lists
 *
 * Return: (void)
 */

void free_listint2(listint_t **head)
{
	listint_t *nt;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		nt = (*head)->next;
		free(*head);
		*head = nt;
	}
}
