#include "main.h"

/**
*get_bit - get the value of a bit in the given Index
*@n: the nbr
*@index: index start frm 0 of the required bit
*
*Return: converted value
*/

int get_bit(unsigned long int n, unsigned int index)
{
	if (index > 63)
		return (-1);

	return ((n >> index) & 1);
}
