#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - a function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);
	int count = 0;
	int value;

	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++; /* move past '%'*/
			if (*p == 'd' || *p == 'i') /*handle %d and %i specifiers*/
			{
				value = va_arg(args, int);
				printf("%d", value);
				count++;
			}
			/*handle other specifiers*/
		}
		else
		{
			putchar(*p);
			count++;
		}
	}
	va_end(args);
	return (count);
}

