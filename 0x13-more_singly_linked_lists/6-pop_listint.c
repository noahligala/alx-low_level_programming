#include "lists.h"

/**
 * pop_listint - deletes the head node.
 *
 * @head: pointer to the first node.
 *
 * Return: dataof the first node or zero
 * if list is empty.
 */
int pop_listint(listint_t **head)
{
	int dta;
	listint_t *temp;

	if (*head == NULL)
		return (0);

	dta = (*head)->n;
	temp = *head;
	*head = (*head)->next;
	free(temp);

	return (dta);
}
