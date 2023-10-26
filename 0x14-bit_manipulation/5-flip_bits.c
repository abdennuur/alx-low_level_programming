#include "main.h"

/**
*flip_bits - get the nbr of bits to flip to get from the n to the  m
*@n: initial nbr
*@m: fnl nbr
*
*Return: nbr of flipped Bits
*/

unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	unsigned long int flpd = n ^ m;
	int c = 0;

	while (flpd)
	{
		if (flpd & 1)
			c++;
		flpd >>= 1;
	}
	return (c);
}
