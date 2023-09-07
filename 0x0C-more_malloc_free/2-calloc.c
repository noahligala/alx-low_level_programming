#include "main.h"
#include <stdlib.h>

/**
 * _calloc - function that allocates memory for an array, using malloc.
 * @nmemb: The number of blocks to be allocated.
 * @size: the size of each block.
 *
 * Return: the pointer to the pointer of the first memory block on success
 * on failure return NULL.
 */
void *_calloc(uncsigned int nmemb, unsigned int size)
{
	vois *ptr;
	unsigned int i, tot_size;

	/*Check for size values*/
	if (nmemb == 0 || size == 0)
		return (NULL);
	/*calculate the total size required*/

	tot_size = nmemb * size;

	/*Allocate memory using malloc*/
	ptr = malloc(tot_size);

	/*Check for malloc failures*/
	if (ptr == NULL)
		return (NULL);

	/*initialize the allocated memory to zero*/
	for (i = 0; i < tot_size; i++)
		*((char *)ptr + i) = 0;

	return (ptr);
}
