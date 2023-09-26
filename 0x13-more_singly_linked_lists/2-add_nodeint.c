#include "lists.h"

/**
 * add_nodeint - adds a node at the beginning
 * of a linked list.
 * @head: pointer to current head.
 *
 * @n: new element.
 *
 * Return: address of new element on success.
 */
listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new_node = malloc(sizeof(listint_t));

	if (new_node == NULL)
	{
		return (NULL);
	}

	new_node->n = n;
	new_node->next = *head;
	*head = new_node;

	return (new_node);
}
