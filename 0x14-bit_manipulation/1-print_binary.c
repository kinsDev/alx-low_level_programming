#include <stdio.h>
#include "main.h"

void print_binary(unsigned long int n)
{
	if(n > 1)
	{
		print_binary(n / 2);
	}

	printf("%lu", n % 2);
}
