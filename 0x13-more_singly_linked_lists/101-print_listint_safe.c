#include "lists.h"
#include <unistd.h> 

/**
 * _putchar - Writes a character to standard output (stdout).
 * @c: The character to print.
 *
 * Return: 1 on success, -1 on error.
 */
int _putchar(char c)
{
	return write(STDOUT_FILENO, &c, 1);
}

/**
 * print_listint_safe - Prints a listint_t linked list safely.
 * @head: A pointer to the head of the linked list.
 *
 * Return: The number of nodes in the list.
 */
size_t print_listint_safe(const listint_t *head)
{
	size_t count = 0;
	const listint_t *current = head;
	const listint_t *next;

	while (current != NULL)
	{
		next = current->next;

		print_address((void *)current);
		_putchar(' ');
		print_number(current->n);
		_putchar('\n');
		count++;

		if (next >= current)
		{
			_putchar('-');
			_putchar('>');
			_putchar(' ');
			print_address((void *)next);
			_putchar(' ');
			print_number(next->n);
			_putchar('\n');
			break;
		}

		current = next;
	}

	return (count);
}

/**
 * print_address - Prints an address.
 * @address: The address to print.
 */
void print_address(void *address)
{
	size_t i;
	unsigned long int n = (unsigned long int)address;
	char hex_digits[] = "0123456789abcdef"

	_putchar('[');
	for (i = 0; i < 16; i++)
	{
		if (i == 8)
			_putchar(']');
		_putchar(hex_digits[(n >> ((15 - i) * 4)) & 0xF]);
	}
}

/**
 * print_number - Prints an integer.
 * @n: The integer to print.
 */
void print_number(int n)
{
	char buffer[12];
	int i = 0;

	if (n == 0)
	{
		_putchar('0');
		return;
	}
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	while (i > 0)
	{
		_putchar(buffer[--i]);
	}
}
