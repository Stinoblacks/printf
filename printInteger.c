#include "main.h"

/**
* printInt - prints integer
* @args: argument to print
* Return: the integers to be printed
*/
int printInt(va_list args) {
    int n = va_arg(args, int);
    int remainingDigits, lastDigits = n % 10, digit, exp = 1;
    int chars_printed = 0;
    int isNegative = 0;

    if (lastDigits < 0) {
        _putchar('-');
        isNegative = 1;
        remainingDigits = -n;
        lastDigits = -lastDigits;
        chars_printed++;
    } else {
        remainingDigits = n;
    }

    if (remainingDigits > 0) {
        while (remainingDigits / 10 != 0) {
            exp *= 10;
            remainingDigits /= 10;
        }
        remainingDigits = n;

        while (exp > 0) {
            digit = remainingDigits / exp;
            _putchar(digit + '0');
            chars_printed++;
            remainingDigits -= digit * exp;
            exp /= 10;
        }
    }

    _putchar(lastDigits + '0');
    chars_printed++;

    return chars_printed + isNegative;
}