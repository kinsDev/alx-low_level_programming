#include "hash_tables.h"

/**
 * hash_table_print - prints a hash table's contents
 * @ht: pointer to the hash table to print
 *
 * Return: void
 */
void hash_table_print(const hash_table_t *ht)
{
    unsigned long int i;
    hash_node_t *tmp;
    char flag = 0; /* Initialize flag to 0 (indicating no data has been printed yet) */

    if (ht == NULL || ht->array == NULL)
        return;
    printf("{");
    for (i = 0; i < ht->size; i++)
    {
        tmp = ht->array[i];
        while (tmp != NULL)
        {
            if (flag == 1)
                printf(", ");
            printf("'%s': '%s'", tmp->key, tmp->value);
            flag = 1; /* Set flag to 1 (indicating data has been printed) */
            tmp = tmp->next;
        }
    }
    printf("}\n");
}
