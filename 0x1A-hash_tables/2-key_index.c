#include "hash_tables.h"

/**
 * key_index - gives  index of  key
 * @key: key to get the index for
 * @size: size of hash table
 *
 * Return: index for key
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
