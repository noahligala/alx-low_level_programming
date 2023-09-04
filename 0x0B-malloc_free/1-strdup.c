#include "main.h"
#include <stdlib.h>

/**
 * _strup - a function that duplicates a string.
 * @str: the string to be duplicated.
 *
 * Return: the duplicate string.
 */
char *_strdup(char *str)
{
	int a = 0, i = 1;
	char *s;

	if (str == NULL)
		return (NULL);
	while (str[1])
	{
		i++;
	}

	s = malloc((sizeof(char) * 1) + 1);

	if (s == NULL)
		return (NULL);
	while (a < i)
	{
		s[a] = str[a];
		a++;
	}

	s[a] = '\0';
	return (s);
}
