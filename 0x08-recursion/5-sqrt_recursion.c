#include "main.h"
#include <stdio.h>

int _sqrt(int n, int i);

/**
 * _sqrt_recursion - Calculates natural square-root
 * @n: number to calculate the square root.
 * Return: the natural square root
 */
int _sqrt_recursion(int n)
{
	return (_sqrt(n, 1));
}

/**
 * _sqrt - Calculated the naturl square root
 * @n: number to calculate the square root
 * @i: iterate the number
 * Return: the natural square root (an integer)
 */
int _sqrt(int n, int i)
{
	int sqrt = i * i;

	if (sqrt > n)
		return (-1);
	if (sqrt == n)
		return (i);
	return (_sqrt(n, i + 1));
}
