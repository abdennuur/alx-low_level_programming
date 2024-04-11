include "search_algos.h"

/**
 * linear_search - searches for a value in a sorted array of integers
 * @array: array of integers
 * @size: size of array
 * @value: value to search for
 * Return: index of value or -1 if not found
 */


int linear_search(int *array, size_t size, int value)
{
	size_t inv;

	if (array == NULL)
		return (-1);
	for (inv = 0; inv < size; inv++)
	{
		printf("Value checked array[%ld] = [%d]\n", inc, array[inc]);
		if (array[inv] == value)
			return (inv);
	}
	return (-1);
}
