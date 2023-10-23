#include "lists.h"

/**
 * reverse_listint -  function that reverse aa listint_t
 * @head: double ptr
 *
 * Return: a ptr to first node of reversed list
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prvs, *nxt;

	if (head == NULL || *head == NULL)
		return (NULL);
	if ((*head)->next == NULL)
		return (*head);
	prvs = NULL;
	while (*head != NULL)
	{
		nxt = (*head)->next;
		(*head)->next = prvs;
		prvs = *head;
		*head = nxt;
	}
	*head = prvs;
	return (*head);
}
