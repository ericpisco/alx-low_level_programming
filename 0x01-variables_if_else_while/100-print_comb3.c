#include<stdio.h>
/**
* main - Entry point
*Return: Always 0 (Success)
*/

int main(void)
{
	int ones = '0';
	int tens = '0';

	for (tens = '0'; tens <= '9'; tens++)
	{
		if (!((ones == tens) || (tens > ones)))
		{
			putchar(tens);
			putchar(ones);
			if (!(ones == '9' && tens == '8'))
			{
				putchar(',');
				putchar(' ');
			}
		}
	}
	putchar('\n');
	return (0);
}


