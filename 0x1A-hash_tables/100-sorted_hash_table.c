#include "hash_tables.h"

/**
 * shash_table_create - create sorted hash table
 * @size: size of hash table
 *
 * Return: ptr to new table, NULL -> failure
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int ix;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);
	ht->size = size;
	ht->shead = NULL;
	ht->stail = NULL;
	ht->array = malloc(sizeof(shash_node_t) * size);
	if (ht->array == NULL)
	{
		free(ht);
		return (NULL);
	}
	for (ix = 0; ix < size; ix++)
	{
		ht->array[ix] = NULL;
	}
	return (ht);
}

/**
 * make_shash_node - make node for sorted hash table
 * @key: the key for data
 * @value: stored data
 *
 * Return: pointer to the new node, or NULL on failure
 */
shash_node_t *make_shash_node(const char *key, const char *value)
{
	shash_node_t *hn;

	hn = malloc(sizeof(shash_node_t));
	if (hn == NULL)
		return (NULL);
	hn->key = strdup(key);
	if (hn->key == NULL)
	{
		free(hn);
		return (NULL);
	}
	hn->value = strdup(value);
	if (hn->value == NULL)
	{
		free(hn->key);
		free(hn);
		return (NULL);
	}
	hn->next = hn->snext = hn->sprev = NULL;
	return (hn);
}

/**
 * add_to_sorted_list - add node to sorted {by key's ASCII} linked list
 * @table: sorted hash table
 * @node: node to add
 *
 * Return:
 */
void add_to_sorted_list(shash_table_t *table, shash_node_t *node)
{
	shash_node_t *temp;

	if (table->shead == NULL && table->stail == NULL)
	{
		table->shead = table->stail = node;
		return;
	}
	temp = table->shead;
	while (temp != NULL)
	{
		if (strcmp(node->key, temp->key) < 0)
		{
			node->snext = temp;
			node->sprev = temp->sprev;
			temp->sprev = node;
			if (node->sprev != NULL)
				node->sprev->snext = node;
			else
				table->shead = node;
			return;
		}
		temp = temp->snext;
	}
	node->sprev = table->stail;
	table->stail->snext = node;
	table->stail = node;
}

/**
 * shash_table_set - set key to value in hash table
 * @ht: the sorted hash table
 * @key: key to data
 * @value: the data to add
 *
 * Return: 1 -> success, 0 -> otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	char *new_val;
	shash_node_t *hn, *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0 || value == NULL)
		return (0);
	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
		{
			new_val = strdup(value);
			if (new_val == NULL)
				return (0);
			free(temp->value);
			temp->value = new_val;
			return (1);
		}
		temp = temp->next;
	}
	hn = make_shash_node(key, value);
	if (hn == NULL)
		return (0);
	hn->next = ht->array[idx];
	ht->array[idx] = hn;
	add_to_sorted_list(ht, hn);
	return (1);
}

/**
 * shash_table_get - retrieve value from hash table
 * @ht: the hash table
 * @key: key to data
 *
 * Return: value associated with key, NULL -> failure
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int idx;
	shash_node_t *temp;

	if (ht == NULL || ht->array == NULL || ht->size == 0 ||
	    key == NULL || strlen(key) == 0)
		return (NULL);
	idx = key_index((const unsigned char *)key, ht->size);
	temp = ht->array[idx];
	while (temp != NULL)
	{
		if (strcmp(temp->key, key) == 0)
			return (temp->value);
		temp = temp->next;
	}
	return (NULL);
}

/**
 * shash_table_print - print sorted hash table
 * @ht: the hash table to print
 *
 * Return:
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *temp;
	char flg = 0; /* 0 -> before printing any data, 1 -> after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	temp = ht->shead;
	while (temp != NULL)
	{
		if (flg == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flg = 1;
		temp = temp->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - print sorted hash table in reverse
 * @ht: the hash table to print
 *
 * Return:
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *temp;
	char flg = 0; /* 0 ->before printing any data, 1-> after*/

	if (ht == NULL || ht->array == NULL)
		return;
	printf("{");
	temp = ht->stail;
	while (temp != NULL)
	{
		if (flg == 1)
			printf(", ");
		printf("'%s': '%s'", temp->key, temp->value);
		flg = 1;
		temp = temp->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - delete sorted hash table
 * @ht: the hash table to delete
 *
 * Return:
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int ix;
	shash_node_t *next;

	if (ht == NULL || ht->array == NULL || ht->size == 0)
		return;
	for (ix = 0; ix < ht->size; ix++)
	{
		while (ht->array[ix] != NULL)
		{
			next = ht->array[ix]->next;
			free(ht->array[ix]->key);
			free(ht->array[ix]->value);
			free(ht->array[ix]);
			ht->array[ix] = next;
		}
	}
	free(ht->array);
	ht->array = NULL;
	ht->shead = ht->stail = NULL;
	ht->size = 0;
	free(ht);
}
