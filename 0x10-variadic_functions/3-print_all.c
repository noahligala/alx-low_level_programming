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
	va_list ap;
	const char *p;
	char *sval;
	int ival;
	double dval;
	char cval;
	int comma = 0;

	va_start(ap, format);
	for (p = format; *p; ++p)
	{
		switch (*p)
		{
			case 'c':
				cval = va_arg(ap, int);
				printf("%s%c", comma ? ", " : "", cval);
				comma = 1;
				break;
			case 'i':
				ival = va_arg(ap, int);
				printf("%s%d", comma ? ", " : "", ival);
				comma = 1;
				break;
			case 'f':
				dval = va_arg(ap, double);
				printf("%s%f", comma ? ", " : "", dval);
				comma = 1;
				break;
			case 's':
				sval = va_arg(ap, char *);
				if (sval == NULL)
					printf("%s(nil)", comma ? ", " : "");
				else
					printf("%s%s", comma ? ", " : "", sval);
				comma = 1;
				break;
		}
	}
	printf("\n");
	va_end(ap);
}
