#include "main.h"

/**
*clear_bit - set bit at position to 0
*@n: used nbr
*@index: cleared position
*
*Return: 1 success, -1 failure
*/

int clear_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || (index > (sizeof(unsigned long int) * 8) - 1))
		return (-1);

	*n &= ~(1 << index);
	return (1);
}
