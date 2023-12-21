#include "hash_tables.h"

/**
 * hash_djb2 - the implementation of djb2 algorithm
 * @str: a string used to generate the hash value
 *
 * Return: the hash value
 */
unsigned long int hash_djb2(const unsigned char *str)
{
	unsigned long int hs;
	int ca;

	hs = 5381;
	while ((ca = *str++))
	{
		hs = ((hs << 5) + hs) + ca; /* hs * 33 + ca */
	}
	return (hs);
}
