#include "main.h"
/**
 * _printf - a function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += printf("%c", va_arg(args, int));
					break;
				case 's':
					count += printf("%s", va_arg(args, char *));
					break;
				case '%':
					count += printf("%%");
					break;
				case 'd':
				case 'i':
					count += printf("%d", va_arg(args, int));
					break;
				case 'u':
					count += printf("%u", va_arg(args, unsigned int));
					break;
				case 'o':
					count += printf("%o", va_arg(args, unsigned int));
					break;
				case 'x':
					count += printf("%x", va_arg(args, unsigned int));
					break;
				case 'X':
					count += printf("%X", va_arg(args, unsigned int));
					break;
				case 'p':
					count += printf("%p", va_arg(args, void *));
					break;
				case 'S':
					count += print_custom_string(va_arg(args, char *));
					break;
				default:
					printf("Invalid format specifier");
					return (-1);
			}
		}
		else
		{
			count += printf("%c", *format);
		}
		format++;
	}

	va_end(args);
	return (count);
}
/**
 * print_custom_string - a helper function that prints a str
 * @s: string to print
 * Return: number of characters printed
 */
int print_custom_string(char *s)
{
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s != '\0')
	{
		if (*s < 32 || *s >= 127)
		{
			count += printf("\\x%02X", *s);
		}
		else
		{
			count += printf("%c", *s);
		}
		s++;
	}

	return (count);
}


