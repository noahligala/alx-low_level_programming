#include "lists.h"
#include <stddef.h> // for NULL definition

/**
 * custom_putchar - A custom function to print a character to the standard output.
 * @c: The character to be printed.
 */
void custom_putchar(char c)
{
	write(1, &c, 1);
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

    while (head != NULL)
    {
        print_address_value(head->n);
        count++;

        if (head <= head->next)
        {
            print_loop_node(head->next->n);
            break;
        }

        head = head->next;
    }

    return (count);
}

/**
 * print_address_value - Prints the address and value of a node.
 * @n: The integer value of the node.
 */
void print_address_value(int n)
{
    print_number_address((size_t)n);

    print_number_value(n);

    custom_putchar('\n');
}

/**
 * print_number_address - Prints the address in a custom format.
 * @n: The address to be printed.
 */
void print_number_address(size_t n)
{
    custom_putchar('[');

    print_hexadecimal_address(n);

    custom_putchar(']');
}

/**
 * print_number_value - Prints the value in a custom format.
 * @n: The value to be printed.
 */
void print_number_value(int n)
{
    if (n < 0)
    {
        custom_putchar('-');
        n = -n;
    }

print_decimal_number((size_t)n);
}

/**
 * print_decimal_number - Prints a decimal number in a custom format.
 * @n: The decimal number to be printed.
 */
void print_decimal_number(size_t n)
{
    size_t divisor = 1;

    while (n / divisor >= 10)
    {
        divisor *= 10;
    }

    while (divisor != 0)
    {
        custom_putchar((char)((n / divisor) % 10 + '0'));
        divisor /= 10;
    }
}

/**
 * print_hexadecimal_address - Prints an address in hexadecimal format.
 * @n: The address to be printed.
 */
void print_hexadecimal_address(size_t n)
{
    char hex_digits[] = "0123456789abcdef";
    char hex_address[16]; // Assuming 64-bit address

    int i;
    for (i = 0; i < 16; i++)
    {
        hex_address[i] = hex_digits[(n >> (60 - 4 * i)) & 0xf];
    }

    for (i = 0; i < 16; i++)
    {
        custom_putchar(hex_address[i]);
    }
}

/**
 * print_loop_node - Prints a loop node in a custom format.
 * @n: The value of the loop node.
 */
void print_loop_node(int n)
{
    custom_putchar('\n');
    custom_putchar('-');
    custom_putchar('>');
    custom_putchar(' ');

    print_number_address((size_t)n);
    print_number_value(n);

    custom_putchar('\n');
}
