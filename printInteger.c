#include "main.h"

/**
* printInt - prints integer
* @args: argument to print
* Return: the integers to be printed
*/
int printInt(va_list args) {
    int n = va_arg(args, int);
    int num, last = n % 10, digit, exp = 1;
    int chars_printed = 0;
    int isNegative = 0;

    if (last < 0) {
        _putchar('-');
        isNegative = 1;
        num = -n;
        last = -last;
        chars_printed++;
    } else {
        num = n;
    }

    if (num > 0) {
        while (num / 10 != 0) {
            exp *= 10;
            num /= 10;
        }
        num = n;

        while (exp > 0) {
            digit = num / exp;
            _putchar(digit + '0');
            chars_printed++;
            num -= digit * exp;
            exp /= 10;
        }
    }

    _putchar(last + '0');
    chars_printed++;

    return chars_printed + isNegative;
}