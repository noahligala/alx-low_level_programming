#include "main.h"

/**
 * _strcpy - function to copy string
 *
 * @dest: function parameter
 *
 * @src: function parameter
 *
 * Return: returns value of dest when succesful
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0 ; src[i] != '\0' ; i++)
	{
		dest[i] = src[i];
	}
	dest[i++] = '\0';
	return (dest);
}
