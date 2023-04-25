#include "main.h"
/**
 * _printf - a function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0; /*count of characters printed*/
	va_list args;
	char *s, c;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++; /*move past the '%' */
			if (*format == 'c')
			{
				c = va_arg(args, int);
				putchar(c);
				count++;
			}
			else if (*format == 's')
			{
				s = va_arg(args, char *);
				while (*s != '\0')
				{
					putchar(*s);
					s++;
					count++;
				}
			}
			else if (*format == '%')
			{
				putchar('%');
				count++;
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args); /*end variable arguments*/
	return (count);
}

