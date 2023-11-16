#include "main.h"
#include <stdlib.h>

/**
 * check_for_specifiers - function that checks for a valid format specifier
 * @format: possible format specifier
 *
 * Return: pointer to valid function or NULL
 */
static int (*check_for_specifiers(const char *format))(va_list)
{
	unsigned int i;
	print_t p[] = {
		{"c", print_c},
		{"s", print_s},
		{"i", print_i},
		{"d", print_d},
		{"u", print_u},
		{"b", print_b},
		{"o", print_o},
		{"x", print_x},
		{"X", print_X},
		{"p", print_p},
		{"S", print_S},
		{"r", print_r},
		{"R", print_R},
		{NULL, NULL}
	};

	for (i = 0; p[i].t != NULL; i++)
	{
		if (*(p[i].t) == *format)
			break;
	}
	return (p[i].f);
}

/**
 * handle_non_specifier - function to handle characters that are not format specifiers
 * @ch: character to be handled
 *
 * Return: 1 if character is printed, 0 otherwise
 */
static int handle_non_specifier(char ch)
{
	if (ch != '%')
	{
		_putchar(ch);
		return (1);
	}
	return (0);
}

/**
 * _printf - function that produces output according to a format.
 * @format: format (char, string, int, decimal)
 *
 * Return: size the output text;
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0, count = 0;
	va_list valist;
	int (*f)(va_list);

	if (format == NULL)
		return (-1);
	va_start(valist, format);
	while (format[i])
	{
		if (handle_non_specifier(format[i]))
		{
			count++;
			i++;
			continue;
		}
		f = check_for_specifiers(&format[i + 1]);
		if (f != NULL)
		{
			count += f(valist);
			i += 2;
		}
		else if (format[i + 1])
		{
			_putchar(format[i]);
			count++;
			if (format[i + 1] == '%')
				i += 2;
			else
				i++;
		}
		else
			return (-1);
	}
	va_end(valist);
	return (count);
}
