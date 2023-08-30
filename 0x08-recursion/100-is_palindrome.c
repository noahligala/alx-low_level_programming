#include "main.h"

/**
 * _strlen_recursion - returns the length of string
 * @s: string
 * Return: the length of the string
 */
int _strlen_recursion(char *s)
{
	if (*s == '\0')
		return (0);
	else
		return (1 + _strlen_recursion(s + 1));
}

/**
 * comp - compares each character of the string
 * @s: string variable
 * @n1: smallest iterator
 * @n2: biggest iterator
 * Return: integer
 */
int comp(char *s, int n1, int n2)
{
	if (*(s + n1) == *(s + n2))
	{
		if (n1 == n2 || n1 == n2 + 1)
			return (1);
		return (0 + comp(s, n1 + 1, n2 - 1));
	}
	return (0);
}
/**
 * is_palindrome - detects if a string is a palindrome
 * @s: string
 * Return: 1 if string is a palindrome else 0
 */
int is_palindrome(char *s)
{
	if (*s == '\0')
		return (1);
	return (comp(s, 0, _strlen_recursion(s) - 1));
}
