#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * _r - reallocates memmory for an array of ptrs
 * to the nodes in linked lst
 * @list: old lst to append
 * @size: size of  new lst (always one more than old list)
 * @new: new node to add to lst
 *
 * Return: ptr to new lst
 */
const listint_t **_r(const listint_t **list, size_t size, const listint_t *new)
{
	const listint_t **nwls;
	size_t j;

	nwls = malloc(size * sizeof(listint_t *));
	if (nwls == NULL)
	{
		free(list);
		exit(98);
	}
	for (j = 0; j < size - 1; j++)
		nwls[j] = list[j];
	nwls[j] = new;
	free(list);
	return (nwls);
}

/**
 * print_listint_safe - prints listint_t a linked list.
 * @head: ptr to the start of list
 *
 * Return: the nbr of nodes in list
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t j, nm = 0;
	const listint_t **list = NULL;

	while (head != NULL)
	{
		for (j = 0; j < nm; j++)
		{
			if (head == list[j])
			{
				printf("-> [%p] %d\n", (void *)head, head->n);
				free(list);
				return (nm);
			}
		}
		nm++;
		list = _r(list, nm, head);
		printf("[%p] %d\n", (void *)head, head->n);
		head = head->next;
	}
	free(list);
	return (nm);
}
