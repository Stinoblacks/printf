#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include <limits.h>

/**
* struct format - converter for printf
* @ph: type char pointer of the specifier
* @function: function for the conversion specifier
*
*/
typedef struct format
{
	char* formatP;
	int (*funcP)();
} picker_t;

/*putcahr header */
int _putchar(char c);

/*_printf header*/
int _printf(const char *format, ...);

/*Header for all function for the format specifiers*/
int printInt(va_list args);
int print_d(va_list args);

#endif /* MAIN_H */
