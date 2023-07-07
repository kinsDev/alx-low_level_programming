#include "main.h"

/**
 * cleart_bit function is used to set a bit to 0
 * if statement - Check if the index is out of range.
 * mask - Create a mask with the bit at the given index set to 0
 */

int clear_bit(unsigned long int *n, unsigned int index)
{
    unsigned long int mask = 1;

    if (index >= sizeof(unsigned long int) * 8)
        return -1;

    mask <<= index;
    mask = ~mask;

    *n &= mask;

    return 1;
}
