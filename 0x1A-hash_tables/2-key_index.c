#include "hash_tables.h"

/**
 * This function calculates the index for a given key in the hash table.
 * 
 * @param key: The key for which the index is calculated.
 * @param size: The size of the hash table.
 * 
 * @return: The index for the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
