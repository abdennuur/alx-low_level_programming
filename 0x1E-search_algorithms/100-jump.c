#include "search_algos.h"
#include <math.h>

/**
 * jump_search - fnction to searches for  value
 * in a sorted array of ints
 *
 * @array: a ptr to first element of array to search in
 * @size:  the nbr of elements in array
 * @value: value to search for
 * Return: first index where value's located
 */

int jump_search(int *array, size_t size, int value)
{
	size_t stp = sqrt(size);
	size_t prv = 0;
	size_t ix;

	if (array == NULL)
		return (-1);

	while (array[prv] < value && prv < size)
	{
		printf("Value checked array[%ld] = [%d]\n", prv, array[prv]);
		prv += stp;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", prv - stp, prv);

	for (ix = prv - stp; ix <= prv && ix < size; ++ix)
	{
		printf("Value checked array[%ld] = [%d]\n", ix, array[ix]);
		if (array[ix] == value)
			return (ix);
	}

	return (-1);
}
