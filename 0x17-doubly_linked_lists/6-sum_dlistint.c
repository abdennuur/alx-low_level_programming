#include "lists.h"

/**
 * sum_dlistint - sum all of data of dlistint_t linked list
 * @head: ptr to beginning of linked list
 *
 * Return: sum of all data, or 0 -> the empt list
 */
int sum_dlistint(dlistint_t *head)
{
	int sm = 0;

	while (head != NULL)
	{
		sm += head->n;
		head = head->next;
	}
	return (sm);
}
