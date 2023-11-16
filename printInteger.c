#include "main.h"
/**
* printInt - prints integer
* @args: argument to print
* Return: the integers to be printed
*/
int printInt(va_list args)
{
	int n = va_arg(args, int);
	int remainingDigits, digit, exp = 1;
	int chars_printed = 0;
	int isNegative = 0;

	if (n < 0)
	{
		_putchar('-');
		n = -n;
		chars_printed++;
		isNegative = 1;
	}

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	remainingDigits = n;

	while (remainingDigits / exp > 9)
	{
		exp *= 10;
	}

	while (exp > 0)
	{
		digit = remainingDigits / exp;
		_putchar(digit + '0');
		chars_printed++;
		remainingDigits -= digit * exp;
		exp /= 10;
	}

	return (chars_printed + isNegative);
}
