#include "main.h"

/**
 * binary_to_uint - function that converts a binary digit to an unsigned int.
 * @b: pointer to a string.
 *
 * Return: the converted number.
 */

unsigned int binary_to_uint(const char *b)
{
	unsigned int result = 0;

	if (b == NULL)
		return (0);

	while (*b)
	{
		if (*b == '0' || *b == '1')
		{
			result = result * 2 + (*b - '0');
			b++;
		}
		else
		{
			return (0);
		}

	}

	return (result);
}
