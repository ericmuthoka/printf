#include <stdio.h>
#include <stdarg.h>
/**
 * _printf - prints output
 * @format: a character string
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	int value;
	int count = 0;

	va_start(args, format);
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

