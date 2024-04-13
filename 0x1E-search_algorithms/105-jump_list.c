#include "search_algos.h"

/**
 * jump_list - to searche for algo in sorted singly
 *             linked list of ints using jump search.
 * @list: ptr to  head of linked list to search.
 * @size: nbr of nodes in list.
 * @value: value to search for.
 *
 * Return: NULL -> if the value is not present or the head of listis NULL.
 *         Otherwise, a ptr to first node where value is located.
 *
 * Description: to print  value every time it compared in list.
 *              Use square root of list size as jump step.
 */
listint_t *jump_list(listint_t *list, size_t size, int value)
{
	size_t stp, stp_sz;
	listint_t *nd, *jmp;

	if (list == NULL || size == 0)
		return (NULL);

	stp = 0;
	stp_sz = sqrt(sz);
	for (nd = jmp = list; jmp->index + 1 < size && jmp->n < value;)
	{
		nd = jmp;
		for (stp += stp_sz; jmp->index < stp; jmp = jmp->next)
		{
			if (jmp->index + 1 == size)
				break;
		}
		printf("Value checked at index [%ld] = [%d]\n", jmp->index, jmp->n);
	}

	printf("Value found between indexes [%ld] and [%ld]\n",
			nd->index, jmp->index);

	for (; nd->index < jmp->index && nd->n < value; nd = nd->next)
		printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);
	printf("Value checked at index [%ld] = [%d]\n", nd->index, nd->n);

	return (nd->n == value ? nd : NULL);
}
