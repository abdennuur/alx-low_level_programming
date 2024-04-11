#include "search_algos.h"

/**
 * binary_search - to searches for value in sorted array of ints
 * using binary search algo
 * @array: array of ints
 * @size: size of arr
 * @value: value to search for it
 * Return: )-> index of value or -> -1 if not found
 */

int binary_search(int *array, size_t size, int value)
{

	size_t ix, lft, rght;

	if (array == NULL)
		return (-1);

	for (lft = 0, rght = size - 1; rght >= lft;)
	{
		printf("Searching in array: ");
		for (ix = lft; ix < rght; ix++)
			printf("%d, ", array[ix]);
		printf("%d\n", array[ix]);

		ix = lft + (rght - lft) / 2;
		if (array[ix] == value)
			return (ix);
		if (array[ix] > value)
			rght = ix - 1;
		else
			lft = ix + 1;
	}

	return (-1);
}
