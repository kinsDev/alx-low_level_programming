#include "hash_tables.h"

/**
 * hash_djb2 - This function implements the djb2 hashing algorithm.
 * @str: The string used to generate the hash value.
 *
 * Return: The calculated hash value.
 */
unsigned long int hash_djb2(const unsigned char *str)
{
    unsigned long int hash; /* Initialize the hash variable. */
    int c; /* Variable to hold the current character being processed. */

    hash = 5381; /* Initialize the hash with a prime number. */
    while ((c = *str++)) /* Loop through each character in the input string. */
    {
        /* Update the hash using the djb2 formula: hash * 33 + c */
        hash = ((hash << 5) + hash) + c;
    }
    return (hash); /* Return the calculated hash value. */
}
