#include "main.h"
/**
 * _islower - checks is a character is in lower case
 *
 * @c: parameter being checked
 *
 * Return: 1 if lowercase otherwise 0
 */
int _islower(int c)
{
	if (c >= 97 && c <= 122)
		return (1);
	else
		return (0);
}
