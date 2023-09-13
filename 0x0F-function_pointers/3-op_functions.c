#include "3-calc.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * op_add - function that adds two integers.
 * @a: function parameter.
 * @b: function parameter.
 *
 * Return: an interger.
 */
int op_add(int a, int b)
{
	return (a + b);
}

/**
 * op_sub - function that subtracts two integers
 * @a: function parameter.
 * @b: function parameter.
 *
 * Return: An integer on success
 */
int op_sub(int a, int b)
{
	return (a - b);
}

/**
 * op_mul - function that multiplies two integers.
 * @a: function parameter.
 * @b: function parameter.
 *
 * Return: An integer on success.
 */
int op_mul(int a, int b)
{
	return (a * b);
}

/**
 * op_div - a function that divides two integers.
 * @a: function parameter.
 * @b: function parameter.
 *
 * Return: an integer on success.
 */
int op_div(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a / b);
}

/**
 * op_mod - function that returns the remainder of a division btwn
 * two integers.
 * @a: function parameter.
 * @b: function parameter.
 *
 * Return: an integer on success.
 */
int op_mod(int a, int b)
{
	if (b == 0)
	{
		printf("Error\n");
		exit(100);
	}
	return (a % b);
}
