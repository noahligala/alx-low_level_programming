#include "lists.h"

/**
 * sum_listint - returns the sum of all the elements
 * of linked list.
 *
 * @head: pointer to a pointer for the first node
 * in a linked list.
 *
 * Return: returns the sum of all the elements of a linked list and
 * 0 if the list is empty.
 */
int sum_listint(listint_t *head)
{
	int sum = 0;

	while (head != NULL)
	{
		sum += head->n;
		head = head->next;
	}

	return (sum);
}
