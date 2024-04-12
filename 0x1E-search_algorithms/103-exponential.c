#include <stdio.h>
#include <stdlib.h>
#include "search_algos.h"

/**
 * binary_search - Perform binary search within a given array and range
 * @array: Pointer to the first element of the array
 * @start: Starting index of the search range
 * @end: Ending index of the search range
 * @value: Value to search for
 *
 * Return: Index of the element if found, -1 otherwise
 */
int binary_search(int *array, size_t start, size_t end, int value)
{
    while (start <= end)
    {
        size_t mid = (start + end) / 2;

        printf("Searching in array: ");
        for (size_t i = start; i <= end; i++)
        {
            printf("%d", array[i]);
            if (i < end)
                printf(", ");
            else
                printf("\n");
        }

        if (array[mid] == value)
            return (mid);
        else if (array[mid] < value)
            start = mid + 1;
        else
            end = mid - 1;
    }
    return (-1);
}

/**
 * exponential_search - Search for a value in a sorted array using exponential search
 * @array: Pointer to the first element of the array
 * @size: Number of elements in array
 * @value: Value to search for
 *
 * Return: Index of the first occurrence of value, or -1 if not found
 */
int exponential_search(int *array, size_t size, int value)
{
    size_t bound = 1;

    if (array == NULL)
        return (-1);

    while (bound < size && array[bound] < value)
    {
        printf("Value checked array[%lu] = [%d]\n", bound, array[bound]);
        bound *= 2;
    }

    size_t start = bound / 2;
    size_t end = (bound < size - 1) ? bound : size - 1;

    printf("Value found between indexes [%lu] and [%lu]\n", start, end);

    return binary_search(array, start, end, value);
}

