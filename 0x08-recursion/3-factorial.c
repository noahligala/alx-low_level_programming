#include "main.h"

/**
 * factorial - function that calculates the factorial
 * of a givrn number
 * @n: integer for which the factorial is to be calculated 
 * Return: integer value
 */
int factorial(int n)
{
	if(n < 0)
		return (-1);
	if (n <= 1)
		return (1);
	return (n* factorial(n - 1));
}
