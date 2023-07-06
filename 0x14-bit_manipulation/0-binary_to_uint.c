#include "main.h"

/**
 * This function converts a binary to an unsigned int
 * b is the binary number as a string
 */

#include <stdio.h>

unsigned int binary_to_uint(const char *b)
{
    unsigned int result = 0;

    if (!b)
        return 0;

    while (*b)
    {
        if (*b == '0')
        {
            result <<= 1; // Left-shift result by 1
        }
        else if (*b == '1')
        {
            result <<= 1; // Left-shift result by 1
            result |= 1;  // Set the least significant bit to 1
        }
        else
        {
            return 0; // Invalid input character
        }

        b++; // Move to the next character
    }

    return result;
}
