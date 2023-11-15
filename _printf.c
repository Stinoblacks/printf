#include "main.h"
#include <stdlib.h>
#include <string.h>

/**
 * select_format - selects the correct function to handle a format specifier
 * @fmt: format specifier
 * @args: list of arguments
 * @p: array of format and function pairs
 * Return: the number of characters printed
 */

int select_format(const char *fmt, va_list args, picker_t *p)
{
	int i = 0, j, length = 0;
	int found = 0;

	while (fmt[i] != '\0')
	{
		if (fmt[i] == '%')
		{
			j = 0;
			found = 0;

			while (p[j].formatP)
			{
				if (strncmp(fmt + i, p[j].formatP, strlen(p[j].formatP)) == 0)
				{
					length += p[j].funcP(args);
					i += strlen(p[j].formatP);
					found = 1;
					break;
				}
				j++;
			}

			if (!found)
			{
				_putchar(fmt[i]);
				length++;
				i++;
			}
		}
		else
		{
			_putchar(fmt[i]);
			length++;
			i++;
		}
	}
	return (length);
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	if (format == NULL)
		return (-1);

	if (strcmp(format, "% ") == 0)
	{
		_putchar('%');
		_putchar(' ');
		return (2);
	}

	if (strcmp(format, "%\0") == 0)
	{
		_putchar('%');
		_putchar('\0');
		return (2);
	}

	va_list args;
	int length;

	picker_t p[] = {
		{"%i", printInt},
		{"%d", printInt},
		{"%%", print_mod},
		{"%c", print_c},
		{"%s", print_s},
		{"%S", print_S},
		{NULL, NULL}};

	va_start(args, format);
	length = select_format(format, args, p);
	va_end(args);

	return (length);
}

