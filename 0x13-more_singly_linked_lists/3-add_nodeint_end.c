#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint_end - add node in the end of a listint_t list.
  *
  * @head: head of double ptr
  * @n: integer add the list
  * Return: NULL if fail
  */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *nw;
	listint_t *tmp;

	if (head == NULL)
		return (NULL);
	nw = malloc(sizeof(listint_t));
	if (nw == NULL)
		return (NULL);
	nw->n = n;
	nw->next = NULL;
	if (*head == NULL)
	{
	*head = nw;
		return (nw);
	}
	tmp = *head;
	while (tmp->next != NULL)
	{
		tmp = tmp->next;
	}
	tmp->next = nw;
	return (nw);
}
