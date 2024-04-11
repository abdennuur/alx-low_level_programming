#include "search_algos.h"

/**
 * linear_search - to searche for a value in sorted array of ints
 * @array: array of ints
 * @size: size of arry
 * @value: value to search for it
 * Return: ->index of value or -> -1 if not found
 */


int linear_search(int *array, size_t size, int value)
{
	size_t intv;

	if (array == NULL)
		return (-1);
	for (intv = 0; intv < size; intv++)
	{
		printf("Value checked array[%ld] = [%d]\n", intv, array[intv]);
		if (array[intv] == value)
			return (intv);
	}
	return (-1);
}
