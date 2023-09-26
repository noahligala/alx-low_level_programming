#include "lists.h"
#include <stdio.h>

/**
 * print_listint - prints all the members of
 * a linked list.
 * @h: pointer to the head of the first node.
 * Return: number of nodes in linked list.
 */
size_t print_listint(const listint_t *h)
{
	size_t count = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
