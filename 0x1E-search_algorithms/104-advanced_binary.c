#include "search_algos.h"

/**
  * advanced_binary_recursive - to Searche recursively for value in sorted
  *                             array of ints using binary search
  * @array: ptr to first element of [sub]array to search.
  * @left: starting index of [sub]array to search.
  * @right: ending index of [sub]array to search.
  * @value: value to search
  *
  * Return: -1 value not prsnt
  *         Otherwise,index where value is located.
  *
  * Description: to print the [sub]array being searched after each change.
  */
int advanced_binary_recursive(int *array, size_t left, size_t right, int value)
{
	size_t ix;

	if (right < left)
		return (-1);

	printf("Searching in array: ");
	for (ix = left; ix < right; ix++)
		printf("%d, ", array[ix]);
	printf("%d\n", array[ix]);

	ix = left + (right - left) / 2;
	if (array[ix] == value && (ix == left || array[ix - 1] != value))
		return (ix);
	if (array[ix] >= value)
		return (advanced_binary_recursive(array, left, ix, value));
	return (advanced_binary_recursive(array, ix + 1, right, value));
}

/**
  * advanced_binary - to searche for value in sorted array
  *                   of ints using advanced binary search.
  * @array: ptr to the first element of array to search.
  * @size: nbr of elements in array.
  * @value: value to search for.
  *
  * Return: NULL if value not present, -1.
  *         Otherwise, first index where value located.
  *
  * Description: to print [sub]array being searched after each change.
  */
int advanced_binary(int *array, size_t size, int value)
{
	if (array == NULL || size == 0)
		return (-1);

	return (advanced_binary_recursive(array, 0, size - 1, value));
}
