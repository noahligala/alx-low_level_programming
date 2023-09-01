#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * is_positive_number - check if a string is apositive number
 * @str: The string to check
 *
 * Return: 1 if positive else 0
 */

int is_positive_number(const char *str)
{
	if (str == NULL || *str == '\0')
		return (0);

	while (*str)
	{
		if (!isdigit(*str))
			return (0);
		str++;
	}

	return (1);
}

/** main - Entry Point
 * @argc: The number of command-line arguments
 * @argv: An array of commandline argument strings
 *
 * Return: 0 on success else 1
 */

int main(int argc, char *argv[])
{
	int sum = 0;
	int i;

	if (argc == 1)
	{
		printf("0\n");
		return (0);
	}

	for (i = 1; i < argc; i++)
	{
		if (is_positive_number(argv[i]))
		{
			int num = atoi(argv[i]);
			if (num < 0 || (sum + num <sum))
			{
				printf("Error\n");
				return (1);
			}
			sum += num;
		}
		else
		{
			printf("Error\n");
			return (1);
		}
	}

	printf("%d\n", sum);
	return (0);
}
