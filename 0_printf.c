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
	if (format == NULL)
	{
		return (-1);
	}
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

