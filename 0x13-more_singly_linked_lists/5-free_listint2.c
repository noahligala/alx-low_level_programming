#include "lists.h"

/**
 * free_listint2 - frees up a linked list.
 * @head: pointer to the first node.
 *
 * Return: Nothing.
 */
void free_listint2(listint_t **head)
{
	listint_t *current;

	if (head == NULL)
		return;
	while (*head != NULL)
	{
		current = *head;
		*head = (*head)->next;
		free(current);
	}

	*head = NULL;
}
