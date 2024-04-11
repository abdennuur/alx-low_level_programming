#include "search_algos.h"

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
	size_t ix, stp, jmp;

	if (array == NULL || size == 0)
		return (-1);

	stp = sqrt(size);

	for (ix = jmp = 0; jmp < size && array[jmp] < value;)
	{
		printf("Value checked array [%ld] = [%d]\n", jmp, array[jmp]);
		ix = jmp;
		jmp += stp;
	}

	printf("Value found between indexes [%ld] and [%ld]\n", ix, jmp);

	jmp = jmp > size - 1 ? jmp : size - 1;
	for (; ix < size && array[ix] < value; ix++)
	{
		printf("Value checked array [%ld] = [%d]\n", ix, array[ix]);
	}
	printf("Value checked array [%ld] = [%d]\n", ix, array[ix]);

	return (array[ix] == value ? (int)ix : -1);
}
