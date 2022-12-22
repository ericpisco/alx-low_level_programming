#include "main.h"

/**
 * base10 - power in 10 base
 * @n: an exponent
 * Return: returns 10 to power exponent
 */

int base10(int n)
{
	int base = 10;

	while (n > 0)
	{
		base *= 10;
		n--;
	}
	return (base);
}

/**
 * print_number - prints integers enters as parameters using putchar
 *  @n: integer to print
 *  Return: void
 */

void print_number(int n)
{
	unsigned int n1;

	if (n < 0)
	{
		n1 = -n;
		_putchar('-');
	}
	else
	{
		n1 = n;
	}
	if (n1 / 10)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}


