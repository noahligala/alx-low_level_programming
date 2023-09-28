#include "main.h"

/**
 * set_bit - stes the value of a bit to 1 ata given index.
 * @n: pointer to the unsigned long int.
 * @index: the index of the bit to set (starting from 0)
 *
 * Return: 1 if it worked, or -1 if an error occurred.
 */
int set_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);

	*n |= (1UL << index);

	return (1);
}
