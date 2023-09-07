#include "main.h"
#include <stdlib.h>

/**
 * array - function that creates an array of integers.
 * @min: minimum integer value.
 * @max: maximum integer value.
 *
 * Return: pointer to the newly created array on success.
 * if min >  max, return NULL
 * if malloc fails return NULL.
 */
int *array_range(int min, int max)
{
	int *result;
	int size;

	/* Check if min is greater than max*/
	if (min > max)
		return (NULL);

	/*Calculate the size of the array*/
	size = max - min + 1;

	/*Allocate memory for the array using malloc*/
	result = (int *)malloc(size * sizeof(int));

	/*Check if malloc failed*/
	if (result == NULL)
		return (NULL);

	/*Populate the array with values from min to max*/
	for (i = 0; i < size; i++)
		result[i] = min + i;

	/*Return the pointer to the newly created array*/
	return (result);
}
