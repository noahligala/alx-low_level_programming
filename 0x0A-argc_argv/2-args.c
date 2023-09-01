#include <stdio.h>
/**
 * main - prints all the arguments passed into it.
 * @argc: argument count
 * @argv: array of arguments
 * Return: always 0
 */

int main(int argc, char **argv)
{
	int i;

	for (i = 0; i < argc; i++)
	{
		printf("argv[%d] = %s\n", i, argv[i]);
	}
	return (0);
}
