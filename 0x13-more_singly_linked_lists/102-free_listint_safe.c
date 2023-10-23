#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _ra - reallocate memory for array of ptrs
 * to the nodes in linked list
 * @list: the old lst to Append
 * @size: size of new list (always one more than old list)
 * @new: new node to add to list
 *
 * Return: ptr to new list
 */
listint_t **_ra(listint_t **list, size_t size, listint_t *new)
{
	listint_t **nwls;
	size_t j;

	nwls = malloc(size * sizeof(listint_t *));
	if (nwls == NULL)
	{
		free(list);
		exit(98);
	}
	for (j = 0; j < size - 1; j++)
		newlist[j] = list[j];
	nwls[j] = new;
	free(list);
	return (nwls);
}

/**
 * free_listint_safe - frees  listint_t of linked list.
 * @head: double ptr to the start of a list
 *
 * Return: the nbr of nodes in list
 */
size_t free_listint_safe(listint_t **head)
{
	size_t j, nm = 0;
	listint_t **list = NULL;
	listint_t *next;

	if (head == NULL || *head == NULL)
		return (nm);
	while (*head != NULL)
	{
		for (j = 0; j < nm; j++)
		{
			if (*head == list[j])
			{
				*head = NULL;
				free(list);
				return (nm);
			}
		}
		nm++;
		list = _ra(list, nm, *head);
		next = (*head)->next;
		free(*head);
		*head = next;
	}
	free(list);
	return (nm);
}
