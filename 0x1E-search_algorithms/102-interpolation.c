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
	size_t ix, lf, rt;

	if (array == NULL)
		return (-1);

	for (lf = 0, (rt = size - 1); rt >= lf;)
	{
		ix = lf + (((double)(rt - lf) / (array[rt] - array[lf])) * (value - array[lf]));
		if (ix < size)
		{
			printf("Value checked array [%ld] = [%d]\n", ix, array[ix]);
		}
		else
		{
			printf("Value checked array [%ld] is out of range\n", ix);
			break;
		}

		if (array[ix] == value)
			return (ix);
		if (array[ix] > value)
			rt = ix - 1;
		else
			lf = ix + 1;
	}
	return (-1);

}
