#include "main.h"

#include "main.h"

/**
 * power - calculates the result of a number raised to a power
 * @base: the base number
 * @exponent: the exponent
 * Return: the result of base raised to the exponent
 */
unsigned long int power(unsigned int base, unsigned int exponent)
{
	unsigned long int result = 1;
	unsigned int i;

	for (i = 1; i <= exponent; i++)
		result *= base;

	return result;
}

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to be printed in binary
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int divisor, result;
	char flag = 0;

	divisor = power(2, sizeof(unsigned long int) * 8 - 1);

	while (divisor != 0)
	{
		result = n & divisor;
		if (result == divisor)
		{
			flag = 1;
			_putchar('1');
		}
		else if (flag == 1 || divisor == 1)
		{
			_putchar('0');
		}
		divisor >>= 1;
	}
}

