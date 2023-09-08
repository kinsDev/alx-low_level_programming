#include "hash_tables.h"

/**
 * create_hash_table - creates a new hash table
 * @size: size of the hash table array
 *
 * Return: pointer to the newly created hash table
 */
hash_table_t *create_hash_table(unsigned long int size)
{
    hash_table_t *hash_table;
    unsigned long int i;

    hash_table = malloc(sizeof(hash_table_t));
    if (hash_table == NULL)
        return (NULL);
    hash_table->size = size;
    hash_table->array = malloc(size * sizeof(hash_node_t *));
    if (hash_table->array == NULL)
    {
        free(hash_table);
        return (NULL);
    }
    for (i = 0; i < size; i++)
        hash_table->array[i] = NULL;
    return (hash_table);
}
