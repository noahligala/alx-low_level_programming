#ifndef LISTS_H
#define LISTS_H

#include <stddef.h>

typedef struct list_s
{
	char *str;
	size_t len;
	struct list_s *next;
} list_t;

int _putchar(char c);
size_t print_list(const list_t *h);

#endif
