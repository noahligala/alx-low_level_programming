#include <stdio.h>
#include <stdlib.h>

/**
 * main - function that returns multiple of two integers.
 * @argc: the arguments count, no of arguments passed.
 * @argv: array containing the valuesto be multiplied.
 * Return: 0 on success else return 1
 */

int main(int argc, char *argv[])
{
	int num1, num2, result;

	if (argc != 3)
	{
		printf("Error\n");
		return (1);
	}

	num1 = atoi(argv[1]);
	num2 = atoi(argv[2]);

	result = num1 * num2;
	printf("%d\n", result);

	return (0);
}
