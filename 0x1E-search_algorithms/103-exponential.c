#include "search_algos.h"



/**
 * _binary_search - to search for value in sorted array of ints
 * using binary search
 * @array: array of ints
 * @left: Lft element
 * @right: Rght element
 * @value: value search for
 * Return: idx of value or -> -1 if not found
 */

int _binary_search(int *array, size_t left, size_t right, int value)
{

	size_t ix;

	if (array == NULL)
		return (-1);

	while (right > left)
	{
		printf("Searching in array: ");
		for (ix = left; ix < right; ix++)
			printf("%d, ", array[ix]);
		printf("%d\n", array[ix]);

		ix = left + (right - left) / 2;
		if (array[ix] == value)
			return (ix);
		if (array[ix] > value)
			right = ix - 1;
		else
			left = ix + 1;
	}

	return (-1);
}



/**
 * exponential_search -  function to searche for
 *  value in a sorted array of ints
 * @array: potr to first element of array
 * @size:  of array to search in
 * @value: to search for
 *Return: the idx of searched element
 */

int exponential_search(int *array, size_t size, int value)
{
    size_t ix = 1, end, i;

    if (array == NULL)
        return (-1);

    while (ix < size && array[ix] <= value)
    {
        printf("Value checked array[%ld] = [%d]\n", ix, array[ix]);
        ix *= 2;
    }

    printf("Value found between indexes [%ld] and [%ld]\n", ix / 2, ix < size ? ix : size - 1);

    printf("Searching in array: ");
    end = ix < size ? ix : size;
    for (i = ix / 2; i < end; ++i)
    {
        printf("%d", array[i]);
        if (i < end - 1)
            printf(", ");
        else
            printf("\n");
    }

    return _binary_search(array, ix / 2, ix < size ? ix : size - 1, value);
}
