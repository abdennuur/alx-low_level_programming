#include "main.h"

/**
*print_binary - prints binary representation of nbr
*@n: nbr to be printed
*
*Return: (void)
*/ 

void print_binary(unsigned long int n)
{
if (n > 1)
	print_binary(n >> 1);

_putchar((n & 1) + '0');
}
