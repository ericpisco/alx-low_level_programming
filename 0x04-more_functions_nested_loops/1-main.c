#include "main.h"
#include <stdio.h>

/*
 * main - check the code for Holberton School students.
 * Return: 0 Always
 */

int main(void)
{
	char c;

	c = '0';
	printf("%c: %d\n", c, _isdigit(c));
	c = 'a';
	printf("%c: %d\n", c, _isdigit(c));
	return (0);
}
