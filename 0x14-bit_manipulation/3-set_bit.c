#include "main.h"

/**
*set_bit - set bit in position to 1
*@n: used number
*@index: set Index
*
*Return: 1 success, -1 failure
*/

int set_bit(unsigned long int *n, unsigned int index)
{
	if (n == NULL || (index > (sizeof(unsigned long int) * 8) - 1))
		return (-1);

	*n |= (1 << index);
	return (1);
}
