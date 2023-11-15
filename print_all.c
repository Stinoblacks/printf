#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_i - Function to print an integer
 * @args: The va_list containing the integer
 * Return: Number of characters printed
 */
int print_i(va_list args)
{
    int n = va_arg(args, int);
    return printf("%d", n);
}

/**
 * print_d - Function to print a decimal
 * @args: The va_list containing the decimal
 * Return: Number of characters printed
 */
int print_d(va_list args)
{
    int n = va_arg(args, int);
    return printf("%d", n);
}

/**
 * print_u - Function to print an unsigned integer
 * @args: The va_list containing the unsigned integer
 * Return: Number of characters printed
 */
int print_u(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return printf("%u", n);
}

/**
 * print_b - Function to print in binary
 * @args: The va_list containing the binary
 * Return: Number of characters printed
 */
int print_b(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return printf("%u", n);
}

/**
 * print_o - Function to print in octal
 * @args: The va_list containing the octal
 * Return: Number of characters printed
 */
int print_o(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return printf("%o", n);
}

/**
 * print_x - Function to print in lowercase hexadecimal
 * @args: The va_list containing the hexadecimal
 * Return: Number of characters printed
 */
int print_x(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return printf("%x", n);
}

/**
 * print_X - Function to print in uppercase hexadecimal
 * @args: The va_list containing the hexadecimal
 * Return: Number of characters printed
 */
int print_X(va_list args)
{
    unsigned int n = va_arg(args, unsigned int);
    return printf("%X", n);
}

/**
 * print_p - Function to print a pointer address
 * @args: The va_list containing the pointer
 * Return: Number of characters printed
 */
int print_p(va_list args)
{
    void *ptr = va_arg(args, void *);
    return printf("%p", ptr);
}

/**
 * print_R - Function to print the reversed string
 * @args: The va_list containing the string
 * Return: Number of characters printed
 */
int print_R(va_list args)
{
    char *str = va_arg(args, char *);
    int i, count = 0;

    if (str == NULL)
        return -1;

    for (i = 0; str[i]; i++)
        ;
    for (i--; i >= 0; i--)
    {
        _putchar(str[i]);
        count++;
    }

    return count;
}
