#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>
/**
 * print_all - prints everything.
 * @format: list of typed of args
 * Return: Nothing
 */
void print_all(const char * const format, ...)
{
	va_list args;
	char *str;
	int i = 0;
	char current_format;

	va_start(args, format);

	while (format && format[i])
	{
		current_format = format[i];
		switch (current_format)
		{
			case 'c':
				printf("%c", va_arg(args, int));
				break;
			case 'i':
				printf("%d", va_arg(args, int));
				break;
			case 'f':
				printf("%f", (float)va_arg(args, double));
				break;
			case 's':
				str = va_arg(args, char *);
				if (str == NULL)
					printf("(nil)");
				else
					printf("%s", str);
				break;
			default:
				i++;
				continue;
		}
		if (format[i + 1])
			printf(", ");
		i++;
	}

	va_end(args);
	printf("\n");
}
