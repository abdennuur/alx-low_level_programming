#include "lists.h"

/**
 * find_listint_loop - find loop in linked list.
 * @head: ptr to the begin of list
 *
 * Return: address of the node wheen a loop start or NULL if no loop there
 */
listint_t *find_listint_loop(listint_t *head)
{
	listint_t *trts, *hr;

	trts = hr = head;
	while (trts && hr && hr->next)
	{
		trts = trts->next;
		hr = hr->next->next;
		if (trts == hr)
		{
			trts = head;
			break;
		}
	}
	if (!trts || !hr || !hr->next)
		return (NULL);
	while (trts != hr)
	{
		trts = trts->next;
		hr = hr->next;
	}
	return (hr);
}
