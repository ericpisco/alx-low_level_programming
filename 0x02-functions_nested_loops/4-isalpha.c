#include "main.h"

/**
 * _isalpha - Entry point
 * Return: 1 succecc or  fail
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
