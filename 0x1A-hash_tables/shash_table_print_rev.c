#include "hash_tables.h"

/**
 * shash_table_print_rev - Main Point
 * @ht: hash table to print
 */



void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *tail = NULL;

	if (!ht)
		return;

	tail = ht->stail;

	printf("{");
	while (tail)
	{
		printf("'%s': '%s'", tail->key, tail->value);
		if (tail->sprev)
			printf(", ");
		tail = tail->sprev;
	}

	printf("}\n");
}
