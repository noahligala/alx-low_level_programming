#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at the given index.
 *
 * @head: pointer to a pointer of the first node of the linked
 * list.
 *
 * @index: index of the node to be deleted.
 *
 * Return: 1 on success and -1 on failure.
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *current_node, *temp_node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	if (index == 0)
	{
		temp_node = *head;
		*head = (*head)->next;
		free(temp_node);
		return (1);
	}

	current_node = *head;
	for (i = 0; i < index - 1 && current_node != NULL; i++)
		current_node = current_node->next;

	if (current_node == NULL || current_node->next == NULL)
		return (-1);

	temp_node = current_node->next;
	current_node->next = temp_node->next;
	free(temp_node);

	return (1);
}
