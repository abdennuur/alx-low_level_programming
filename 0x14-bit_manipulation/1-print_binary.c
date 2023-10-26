#include "main.h"
/**
 * _power - calcul base and power
 * @base: base of exponet
 * @pow: power of exponet
 * Return: value of the base and the power
 */
unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int nm;
	unsigned int j;

	nm = 1;
	for (j = 1; j <= pow; j++)
		nm *= base;
	return (nm);
}
/**
 * print_binary - print binary representation of a nbr
 * @n: nm of the prented
 * Return: (void)
 */
void print_binary(unsigned long int n)
{
	unsigned long int dv, rslt;
	char flg;

	flg = 0;
	dv = _power(2, sizeof(unsigned long int) * 8 - 1);

	while (dv != 0)
	{
		rslt = n & dv;
		if (rslt == dv)
		{
			flg = 1;
			_putchar('1');

		}
		else if (flg == 1 || dv == 1)
		{
			_putchar('0');
		}
		dv >>= 1;
	}
