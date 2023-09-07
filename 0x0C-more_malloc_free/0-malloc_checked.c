#include "main.h"
#include <stdlib.h>

/**
 * malloc_checked - Allocaes memory using malloc
 * @b: function parameter that indicates the number of bytes to allocate.
 *
 * Return: A pointer to the allocated address on success.
 * on failure function exits with status 98.
 */
void *malloc_checked(unsigned int b)
{
	void *ptr;

	ptr = malloc(b);
	if (ptr == NULL)
		exit(98);

	return (ptr);
}
