#include "hash_tables.h"

/**
 * shash_table_delete - deletes a hash table
 * @ht: hash table to be deleted
 */
void shash_table_delete(shash_table_t *ht)
{
	if (!ht)
		return;

	free_list_s(ht->shead);
	free(ht->array);
	free(ht);
}
