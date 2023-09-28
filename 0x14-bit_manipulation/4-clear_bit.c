#include "main.h"

/**
 * clear_bit - sets the value of abit to a 0 at a given index
 * @n: pointer to the unsigned long int
 * @index: the index of the bit to clear (starting from 0)
 *
 * Return: 1 if successful otherwise -1
 */
int clear_bit(unsigned long int *n, unsigned int index)
{
	if (index >= sizeof(*n) * 8)
		return (-1);

	*n &= (~(1UL << index) & *n);

	return (1);
}
