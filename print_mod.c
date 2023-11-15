#include "main.h"
#include <stdarg.h>

/**
 * print_mod - Print a percentage sign.
 * @args: Argument list (unused).
 *
 * Return: Always returns 1.
 */
int print_mod(va_list args)
{
	(void)args;
	_putchar('%');
	return 1;
}
