#include "main.h"
#include <stdio.h>

/**
 * main - Prints its name
 * @argc: argument(s) count
 * @argv: argument(s) vector/ array of all arguments passed
 * into main
 * Return: 0
 */

int main(int argc, char **argv)
{
	(void) argc;
	printf("%s\n", argv[0]);
	return (0);
}
