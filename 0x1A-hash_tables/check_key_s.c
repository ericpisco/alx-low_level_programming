#include "hash_tables.h"

/**
 * check_key_s - checks if a key exists in a hash table
 * @ht: pointer to the shash_node_t list
 * @key: key to look for
 *
 * Return: 1 if the key is found, 0 otherwise
 */
int check_key_s(shash_node_t *ht, const char *key)
{
	while (ht)
	{
		if (!strcmp(ht->key, key))
			return (1);
		ht = ht->next;
	}

	return (0);
}
