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
* @formatP: type char pointer of the specifier
* @funcP: function for the conversion specifier
*
*/
typedef struct format
{
	char* formatP;
	int (*funcP)();
} picker_t;

/*putcahr header*/
int _putchar(char c);

/*_printf header*/
int _printf(const char *format, ...);

/*Header for all function for the format specifiers*/
int printInt(va_list args);
int print_decimal(va_list args);
int print_c(va_list c);
int print_s(va_list s);
int print_S(va_list S);
int print_r(va_list r);
int print_mod(void);

#endif /* MAIN_H */
