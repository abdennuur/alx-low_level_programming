#include "main.h"

/**
 * get_endianness - check machine is it big endian or little
 *
 * Return: 1 -> little endian, 0 -> big endian
 */

int get_endianness(void)
{
	unsigned int tt = 1;
	char *endian = (char *)&tt;

	if (*endian)
		return (1);
	return (0);

}
