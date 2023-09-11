#include <stdlib.h>

extern char __FILE__[];

int _putchar(char c);

int main(void)
{
	char *file_name = __FILE__;
	char *ptr = file_name;

	while (*ptr)
		ptr++;

	while (ptr >= file_name && *ptr != '/')
		ptr--;
	ptr++;

	while (*ptr)
	{
		_putchar(*ptr);
		ptr++;
	}

	_putchar('\n');

	exit(EXIT_SUCCESS);
}

int _putchar(char c)
{
	return write(1, &c, 1);
}
