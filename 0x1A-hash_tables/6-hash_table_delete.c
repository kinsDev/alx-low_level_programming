#include "hash_tables.h"

/**
 * Function to delete a hash table and its contents.
 * @ht: Pointer to the hash table to be deleted.
 *
 * Return: void
 */
void hash_table_delete(hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *next;

    /* Check if the hash table or its components are NULL or empty */
    if (ht == NULL || ht->array == NULL || ht->size == 0)
        return;

    /* Loop through the hash table */
    for (i = 0; i < ht->size; i++)
    {
        /* Iterate through the linked list at each index */
        while (ht->array[i] != NULL)
        {
            next = ht->array[i]->next;
            free(ht->array[i]->key);
            free(ht->array[i]->value);
            free(ht->array[i]);
            ht->array[i] = next;
        }
    }

    /* Free the array of hash nodes */
    free(ht->array);
    ht->array = NULL;
    ht->size = 0;

    /* Free the hash table itself */
    free(ht);
}
