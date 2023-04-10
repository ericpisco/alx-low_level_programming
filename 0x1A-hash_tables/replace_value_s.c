#include "hash_tables.h"

/**
 * replace_value_s - replaces the value at a pre-existing key
 * @ht: double pointer to the shash_node_t list
 * @key: new key to add in the node
 * @value: value to add in the node
 *
 * Return: 1 on success, 0 on failure
 */
int replace_value_s(shash_node_t **ht, const char *key, const char *value)
{
	shash_node_t *temp = *ht;

	while (temp && strcmp(temp->key, key))
		temp = temp->next;

	free(temp->value);
	temp->value = strdup(value);
	if (!temp->value)
		return (0);
	return (1);
}
