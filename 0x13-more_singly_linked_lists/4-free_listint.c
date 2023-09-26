#include "lists.h"

/**
 * free_listint -frees memory occupied by a
 * linked list.
 *
 * @head: pointer to the first node of the
 * linked list.
 *
 * Return: Nothing.
 */
void free_listint(listint_t *head)
{
	listint_t *current;

	while (head != NULL)
	{
		current = head;
		head = head->next;
		free(current);
	}
}
