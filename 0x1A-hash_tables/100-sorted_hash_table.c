#include "hash_tables.h"
#include "shash_table_print_rev.c"
#include "shash_table_delete.c"
#include "replace_value_s.c"
#include "check_key_s.c"
#include "add_node_s.c"
#include "free_list_s.c"

/**
 * shash_table_create - creates a hash table
 * @size: size of the array of linked list in the table
 *
 * Return: shash_table_t struct
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *sht;

	if (size == 0)
		return (NULL);

	sht = calloc(1, sizeof(shash_table_t));
	if (!sht)
		return (NULL);

	sht->size = size;
	sht->array = calloc((size_t)sht->size, sizeof(shash_node_t *));
	if (sht->array == NULL)
	{
		free(sht);
		return (NULL);
	}

	return (sht);
}

/**
 * shash_table_set - adds an element to the hash table
 * @ht: hash table to add the element to
 * @key: key of the element, will give the index in the array
 * @value: value of the element to store in the array
 *
 * Return: 1 on success, 0 otherwise
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	unsigned long int index;
	shash_node_t *new;

	if (!ht || !key || !strcmp(key, "") || !value)
		return (0);

	index = key_index((unsigned char *)key, ht->size);

	if (check_key_s(ht->array[index], key))
		return (replace_value_s(&ht->array[index], key, value));
	new = add_node_s(&ht->array[index], key, value);
	if (!new)
		return (0);

	insert_sort(new, ht);
	return (1);
}

/**
 * insert_sort - inserts a node in a sorted doubly
 * linked list
 * @node: shash_node_t to insert
 * @ht: pointer to the hash table to insert it into
 */
void insert_sort(shash_node_t *node, shash_table_t *ht)
{
	shash_node_t *head = ht->shead;

	if (!head || strcmp(node->key, head->key) < 0)
	{
		ht->shead = node;
		if (!head)
			ht->stail = node;
		else
		{
			node->snext = head;
			head->sprev = node;
		}
		return;
	}

	while (head->snext && strcmp(node->key, head->snext->key) >= 0)
		head = head->snext;

	node->sprev = head;
	if (!head->snext)
		ht->stail = node;
	else
		head->snext->sprev = node;
	node->snext = head->snext;
	head->snext = node;
}
/**
 * shash_table_get - retrieves a value associated with a key
 * @ht: hash table to look into
 * @key: key of the value to retrieve
 *
 * Return: the value associated with the element,
 * or NULL if key couldn’t be found
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *node = NULL;

	if (!ht || !key || !strcmp(key, ""))
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = (ht->array)[index];

	while (node)
	{
		if (!strcmp(node->key, key))
			return (node->value);
		node = node->next;
	}

	return (NULL);
}

/**
 * shash_table_print - prints a hash table
 * @ht: hash table to print
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *head = NULL;

	if (!ht)
		return;

	head = ht->shead;

	printf("{");
	while (head)
	{
		printf("'%s': '%s'", head->key, head->value);
		if (head->snext)
			printf(", ");
		head = head->snext;
	}

	printf("}\n");
}
