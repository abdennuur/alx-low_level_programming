#include "hash_tables.h"

/**
 * hash_table_create - creates hash table
 * @size: size of array
 *
 * Return: ptr to newly created hash table
 */
hash_table_t *hash_table_create(unsigned long int size)
{
	hash_table_t *hash_tbl;
	unsigned long int ix;

	hash_tbl = malloc(sizeof(hash_table_t));
	if (hash_tbl == NULL)
		return (NULL);
	hash_tbl->size = size;
	hash_tbl->array = malloc(size * sizeof(hash_node_t *));
	if (hash_tbl->array == NULL)
	{
		free(hash_tbl);
		return (NULL);
	}
	for (ix = 0; ix < size; ix++)
		hash_tbl->array[ix] = NULL;
	return (hash_tbl);
}
