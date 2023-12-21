#include "hash_tables.h"

/**
 * hash_table_print - print a hash table
 * @ht: the hash table to print
 *
 * Return:
 */
void hash_table_print(const hash_table_t *ht)
{
	unsigned long int ix;
	hash_node_t *temp;
	char flg = 0; /* 0 -> no data printed  */

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	for (ix = 0; ix < ht->size; ix++)
	{
		temp = ht->array[ix];
		while (temp != NULL)
		{
			if (flg == 1)
				printf(", ");
			printf("'%s': '%s'", temp->key, temp->value);
			flg = 1;
			temp = temp->next;
		}
	}
	printf("}\n");
}
