#include "main.h"

/**
 * get_endianness - checks the endianness of a system
 *
 * Return: 0 if big endian, 1 if small endian.
 */
int get_endianness(void)
{
	unsigned int value = 1;
	unsigned char *byte_ptr = (unsigned char *)&value;

	if (*byte_ptr == 1)
		return (1);

	return (0);
}
