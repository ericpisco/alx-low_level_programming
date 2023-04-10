#include "hash_tables.h"

/**
 * free_list_s - frees a linked list
 * @head: shash_node_t list to be freed
 */
void free_list_s(shash_node_t *head)
{
	shash_node_t *temp;

	while (head)
	{
		temp = head->snext;
		free(head->key);
		free(head->value);
		free(head);
		head = temp;
	}
}
