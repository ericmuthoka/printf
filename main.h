#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>

/**
 * struct fmt - Struct for formatting data
 * @sym: *sym: Pointer to a string
 * @fn: function pointer to a function, takes va_list as an arg.
 */
typedef struct fmt
{
	char *sym;
	int (*fn)(va_list);
} fmt_t;
int print_custom_string(char *s);
int _printf(const char *format, ...);
int (*get_print(const char *format))(va_list);
int print_char(va_list list);
int print_str(va_list list);
int print_perc(va_list list);
int print_int(va_list list);
int print_unsigned(va_list list);
int print_binary(va_list list);
int print_octal(va_list list);
int print_hex(va_list list);
int print_HEX(va_list list);
int print_addrs(va_list list);
int print_STR(va_list list);
unsigned int _strlen(char *s);
void reverse_str(char s[]);
void _itoa(long n, char s[]);
int to_base_n(unsigned long num, int base, char s[]);
char *_memcpy(char *dest, char *src, unsigned int n);
int _putchar(char c);
int _puts(char *str);

#endif


