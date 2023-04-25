#include "main.h"

/**
 * _printf - prints a formatted string to stdout
 * @format: the format of the string to print
 * Return: the number of characters printed to the stdout stream.
 */
int _printf(const char *format, ...)
{
	va_list args;
	int (*pfn)(va_list);
	int i = 0, printed = 0;

	if (!format)
		return (-1);

	va_start(args, format);

	for (; format && format[i]; i++)
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == '\0')
				return (-1);
			for (; format[i + 1] == ' '; i++)
				if (format[i + 2] == '\0')
					return (-1);

			pfn = get_print(&format[++i]);
			printed += pfn ? pfn(args) : _putchar('%') + _putchar(format[i]);
		}
		else
			printed += _putchar(format[i]);
	}

	va_end(args);
	return (printed);
}

