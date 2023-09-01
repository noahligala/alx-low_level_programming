#include <stdio.h>

/**
 * main - prints the number of arguments passed into it.
 * @argc: the arguments count
 * @argv: array of arguments pased into main
 * Return: Always 0
 */

int main(int argc, char **argv)
{
	(void) argv;
	printf("%d\n", argc - 1);
	return (0);
}
