#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * print_char - prints a character
 * @c: character to print
 * @ch_print: pointer to the character count
 */

void print_char(char c, int *ch_print)
{
        write(1, &c, 1);
        (*ch_print)++;
}

/**
 * print_str - prints a string
 * @str: string to print
 * @ch_print: pointer to the character count
 */
void print_str(char *ptr, int *ch_print)
{
        int string_len = 0;

        while (ptr[string_len] != '\0')
        {
                string_len++;
        }
        write(1, ptr, string_len);
        (*ch_print) += string_len;
}

/**
 * _printf - custom printf function
 * @format: format string
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
        int ch_print = 0;
        va_list args_list;

        va_start(args_list, format);

        if (format == NULL)
                return (-1);

        while (*format)
        {
                if (*format != '%' && *format != '\0')
                        print_char(*format, &ch_print);
                else if (*format == '%')
                {
                        format++;
                        if (*format == '\0')
                                break;

                        if (*format == '%')
                                print_char('%', &ch_print);
                        else if (*format == 'c')
                                print_char(va_arg(args_list, int), &ch_print);
                        else if (*format == 's')
                                print_str(va_arg(args_list, char*), &ch_print);
                }

                format++;
        }
        va_end(args_list);
        return (ch_print);
}
