#include "lists.h"

/**
 * reverse_listint - revesers a linked list.
 *
 * @head: pointer to a pointer for the first node of a linked list.
 *
 * Return: pointer to new first node of the linked list.
 */
listint_t *reverse_listint(listint_t **head)
{
	listint_t *prev_node = NULL, *next_node;

	while (*head != NULL)
	{
		next_node = (*head)->next;
		(*head)->next = prev_node;
		prev_node = *head;
		*head = next_node;
	}

	*head = prev_node;
	return (*head);
}
