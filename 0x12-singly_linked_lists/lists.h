#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

/**
 * struct list_s - singly linked list.
 * @str: string - initial malloc allocated string literal.
 * @len: length of the string in bytes (size_t)
 * @next: points to the next node.
 *
 * Description: singly linked list node structure.
 */
typedef struct list_s
{
	char *str;
	size_t len;
	struct list_s *next;
} list_t;

int _putchar(char c);
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node(list_t **head, const char *str);
list_t *add_node_end(list_t **head, const char *str);
void free_list(list_t *head);

#endif
