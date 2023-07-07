#include "main.h"
/**
 * flip_bits - Returns the number of bits you would need to flip to get from one number to another.
 * @n: The first number.
 * @m: The second number.
 *
 * Return: The number of bits you would need to flip.
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
    unsigned long int difference = n ^ m; // Calculate the XOR difference between the two numbers.
    unsigned int count = 0; // Initialize the count of flipped bits.
    unsigned int i;

    // Iterate over each bit position in the difference.
    for (i = 0; i < sizeof(unsigned long int) * 8; i++) {
        // If the current bit is set (i.e., different between the numbers),
        // increment the count of flipped bits.
        if ((difference & 1) == 1) {
            count++;
        }
        difference >>= 1; // Shift the difference to the right to check the next bit.
    }

    return count; // Return the count of flipped bits.
}

