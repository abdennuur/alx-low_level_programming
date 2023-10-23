#include "lists.h"
#include <stdlib.h>
/**
  * add_nodeint - add node in begin of a listint_t list.
  *
  * @head: head of double ptr
  * @n: integer add the list
  * Return: NULL if it fail
  */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *ptrr;

	if (head == NULL)
		return (NULL);
	ptr = malloc(sizeof(listint_t));
	if (ptrr == NULL)
		return (NULL);
	ptrr->n = n;
	ptrr->next = *head;
	*head = ptrr;
	return (ptrr);
}
