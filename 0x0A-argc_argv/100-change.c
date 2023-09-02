#include <stdio.h>
#include <stdlib.h>

/**
 * minCoins - calculate the minimum number of coins needed to
 * make change
 * @cents: the amount of money in cents
 *
 * Return: the minimum number of coins nedded to make change
 */
int minCoins(int cents)
{
	int coins[] = {25, 10, 5, 2, 1};
	int numCoins = 0;
	int i;

	if (cents <= 0)
		return (0);

	for (i = 0; i < 5; i++)
	{
		while (cents >= coins[i])
		{
			cents -= coins[i];
			numCoins++;
		}
	}

	return numCoins;
}

/**
 * main - Entry Point
 * @argc: The number of command-line arguments
 * @argv: array containing all the arguments as a string
 *
 * Return: 0 on success 1 on Error
 */
int main(int argc, char *argv[])
{
	int result, cents;

	if (argc != 2)
	{
		printf("Error\n");
		return (1);
	}

	cents = atoi(argv[1]);

	if (cents < 0)
	{
		printf("0\n");
		return (0);
	}

	result = minCoins(cents);
	printf("%d\n", result);

	return (0);
}
