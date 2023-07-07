#include "main.h"

/**
 * flip_bits - takes argument a & b as inputs+
 * Initialize count to 0 nd keep track of the number of bits that need to be flipped
 * Calculate the XOR (exclusive OR) of a and b using the bitwise XOR operator ^.
 */

int flip_bits(unsigned long int a, unsigned long int b)
{
    unsigned long int xor_result = a ^ b;
    int count = 0;

    while (xor_result != 0) {
        count += xor_result & 1;
        xor_result >>= 1;
    }

    return count;
}

