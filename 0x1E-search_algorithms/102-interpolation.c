#include "search_algos.h"

/**
 *interpolation_search - to searches for value in sorted array of ints
 *@array: potr to first element of array to search in
 *@size: nbr of elements in array
 *@value: value to search for
 *Return: first index where value is located
 */

int interpolation_search(int *array, size_t size, int value)
{
	size_t low = 0, high = size - 1, pos;
	int found = 0;

	if (array == NULL || size == 0)
		return (-1);

	while (low <= high && value >= array[low] && value <= array[high])
	{
		pos = low + (((double)(high - low) / (array[high] - array[low])) *
				(value - array[low]));
		printf("Value checked array[%ld] = [%d]\n", pos, array[pos]);
		if (array[pos] == value)
		{
			printf("Found %d at index: %ld\n", value, pos);
			found = 1;
			break;
		}
		if (array[pos] < value)
			low = pos + 1;
		else
			high = pos - 1;
	}
	if (!found)
		printf("Value %d is not present in the array\n", value);
	return (found ? (int)pos : -1);
}
