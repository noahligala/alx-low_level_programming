#include "main.h"
#include <stdlib.h>

/**
 * argstostr - Concatenates all arguments into  a single string
 * separated by '\n'.
 * @ac: the argument count.
 * @av: Array of argument strings.
 *
 * Return: A pointer to the concatenated string, or NULL if allocation fail
 * or if ac is 0 or if av is NULL.
 */
char *argstostr(int ac, char **av)
{
	int total_length, pos, i, len;
	char *result;

	if (ac == 0 || av == NULL)
		return (NULL);

	pos = 0;
	total_length = 0;

	for (i = 0; i < ac; i++)
	{
		if (av[i] != NULL)
		{
			len = 0;
			while (av[i][len] != '\0')
				len++;
			total_length += len + 1;
		}
	}

	result = malloc(total_length + 1);
	if (result == NULL)
		return (NULL);

	pos = 0;
	for (i = 0; i < ac; i++)
	{
		if (av[i] != NULL)
		{
			len = 0;
			while (av[i][len] != '\0')
				len++;
			result[pos] = av[i][len];
			pos++;
			len = 0;
			while (av[i][len] != '\0')
			{
				result[pos] = av[i][len];
				pos++;
				len++;
			}
			result[pos] = '\n';
			pos++;
		}
	}

	result[total_length] = '\0';

	return (result);
}
