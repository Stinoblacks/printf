#include "main.h"
/**
* select_format - selects the correct function to handle a format specifier
* @fmt: format specifier
* @args: list of arguments
* @p: array of format and function pairs
* Return: the number of characters printed
*/
int select_format(const char *fmt, va_list args, picker_t *p)
{
	int i = 0, j, lenght = 0;
	int found = 0;

	while (fmt[i] != '\0')
	{
		j = 0;

		while (p[j].formatP)
		{
			if (strcmp(fmt + i, p[j].formatP) == 0)
			{
				lenght += p[j].funcP(args);
				i += strlen(p[j].formatP);
				found = 1;
				break;
			}
			j++;
		}
		if (!found)
		{
			_putchar(fmt[i]);
			lenght++;
			i++;
		}
	}
	return (lenght);
}

/**
* _printf - custom printf function
* @format: format string
* Return: number of characters printed
*/
int _printf(const char *format, ...)
{
	va_list args;
	int lenght;

	picker_t p[] = {
		{"%i", printInt},
		{"%d", print_decimal},
		{"%%", print_mod},
		{"%c", print_c},
		{"%s", print_s},
		{"%S", print_S},
		{"%X", hex_print},
		{NULL, NULL}
	};

	va_start(args, format);
	if (format == NULL)
		return (-1);

	lenght = select_format(format, args, p);

	va_end(args);
	return lenght;
}
