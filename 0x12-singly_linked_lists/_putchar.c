#include <unistd.h>

/**
 * _putchar - writes the character to stdout.
 * @c: the character to print.
 *
 * Return: 1 on Succes.
 */
int _putchar(char c)
{
	return(write(1, &c, 1));
}
