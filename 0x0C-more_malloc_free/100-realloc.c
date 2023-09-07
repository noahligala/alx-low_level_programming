#include <stdlib.h>
#include "main.h"

/**
 * _realloc - Reallocates a memory block using malloc and free.
 * @ptr: A pointer to the memory previously allocated with malloc.
 * @old_size: The size, in bytes, of the allocated space for ptr.
 * @new_size: The new size, in bytes, of the new memory block.
 *
 * Return: If new_size is zero and ptr is not NULL, it frees the memory
 *         pointed to by ptr and returns NULL. If ptr is NULL, it behaves
 *         like a regular malloc call and returns a pointer to a new block
 *         of memory of size new_size. If new_size is equal to old_size,
 *         it does nothing and returns the original ptr. Otherwise, it
 *         allocates a new block of memory of size new_size, copies the
 *         data from the old block to the new block (up to the minimum of
 *         old_size and new_size), and then frees the old block. Finally,
 *         it returns a pointer to the new block of memory.
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
    {
        return (malloc(new_size));
    }

    if (new_size == old_size)
    {
        return (ptr);
    }

    /* Determine the minimum size between old_size and new_size */
    min_size = (old_size < new_size) ? old_size : new_size;

    /* Allocate a new block of memory of the requested size */
    new_ptr = malloc(new_size);
    if (new_ptr == NULL)
    {
        return (NULL); /* Memory allocation failed */
    }

    /* Copy the contents of the old block to the new block, up to min_size bytes */
    for (i = 0; i < min_size; i++)
    {
        *((char *)new_ptr + i) = *((char *)ptr + i);
    }

    /* Free the old block */
    free(ptr);

    return (new_ptr);
}