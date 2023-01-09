#include <stdio.h>

/**
 * main - Prints all arguments it receives.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 * return: 0 Always
 */

int main(int argc, char *argv[])
{
	int arg;

	for (arg = 0; arg < argc; arg++)
		printf("%s\n", argv[arg]);

	return (0);

}
