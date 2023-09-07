#include "main.h"
#include <stdlib.h>

/**
 * _realloc - Reallocates a memory block using malloc and free
 * @ptr: A pointer to the memory previously allocated with malloc.
 * @old_size: The size of the allocated space for ptr.
 * @new_size: the new size for the new memory block.
 *
 * Return: a pointer to the new memory block.
 */
void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size)
{
	unsigned int min_size, i;
	void *new_ptr;

	if (new_size == 0)
	{
		free(ptr);
		return (NULL);
	}

	if (ptr == NULL)
		return (malloc(new_size));

	if (new_size == old_size)
		return (ptr);

	/*Determination of the min size btwn old and new_size*/
	min_size = (old_size < new_size) ? old_size : new_size;

	/*Allocate a new block of memory of the requested size*/
	new_ptr = malloc(new_size);
	if (new_ptr == NULL)
		return (NULL); /*memory allocation failed*/

	/*Copy the contents of the old block to the new block*/
	for (i = 0; i < min_size; i++)
		*((char *)new_ptr + i) = *((char *)ptr + 1);

	/*Free old block*/
	free(ptr);

	return (new_ptr);
}
