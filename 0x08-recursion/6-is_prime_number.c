#include "main.h"
#include <stdio.h>

int check_prime(int n, int i);

/**
 * is_prime_number - Returns 1 if number is a prime number
 * @n: the number to be checked.
 * Return: integer value 1 if prime number else 0
 */
int is_prime_number(int n)
{
	return (check_prime(n, 1));
}

/**
 * check_prime -check if the number is a prime number
 * @n: the number to be checked
 * @i: the iterative number
 * Return: 1 for prime number or 0 for composite
 */
int check_prime(int n, int i)
{
	if (n <= 1)
		return (0);
	if (n % i == 0 && i > 1)
		return (0);
	if (n / i < i)
		return (1);
	return (check_prime(n, i + 1));
}
