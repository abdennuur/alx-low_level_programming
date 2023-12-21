
#include "hash_tables.h"

/**
 * hash_table_delete - Delete hash table
 * @ht: ptr to hash table
 */
void hash_table_delete(hash_table_t *ht)
{
	hash_table_t *hd = ht;
	hash_node_t *nd, *temp;
	unsigned long int ix;

	for (ix = 0; ix < ht->size; ix++)
	{
		if (ht->array[ix] != NULL)
		{
			nd = ht->array[ix];
			while (nd != NULL)
			{
				temp = nd->next;
				free(nd->key);
				free(nd->value);
				free(nd);
				nd = temp;
			}
		}
	}
	free(hd->array);
	free(hd);
}
