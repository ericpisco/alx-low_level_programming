#include "main.h"

/**
 * _isalpha - checks the code
 *  @c: is c an integer argument
 * Return: 1 success or 0 fail
 */

int _isalpha(int c)
{
	if (c >= 97 && c <= 122)
	{
		return (1);
	}
	else if (c >= 65 && c <= 90)
	{
		return (1);
	}
	return (0);
}

