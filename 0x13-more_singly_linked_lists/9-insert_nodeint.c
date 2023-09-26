#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a
 * given position.
 *
 * @idx: index of the list where the node should be added.
 *
 * @n: integer, data of the new node.
 *
 * @head: pointer to the first node of the linked list.
 *
 * Return: Address of the new node or NULL if failed,
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *current_node;
	unsigned int i;

	if (head == NULL)
		return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (new_node == NULL)
		return (NULL);

	new_node->n = n;

	if (idx == 0)
	{
		new_node->next = *head;
		*head = new_node;
		return (new_node);
	}

	current_node = *head;
	for (i = 0; i < idx - 1 && current_node != NULL; i++)
		current_node = current_node->next;

	if (current_node == NULL)
	{
		free(new_node);
		return (NULL);
	}

	new_node->next = current_node->next;
	current_node->next = new_node;

	return (new_node);
}
