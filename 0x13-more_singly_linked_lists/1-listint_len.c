#include "lists.h"

/**
 * listint_len - returns the number of elements
 * in a linked list.
 * @h: pointer to address of the first node.
 *
 * Return: The number of elements in the linked list.
 */
size_t listint_len(const listint_t *h)
{
	size_t node_count = 0;

	while (h != NULL)
	{
		node_count++;
		h = h->next;
	}

	return (node_count);
}
