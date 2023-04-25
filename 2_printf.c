#include "main.h"
/**
 * print_binary - prints binary
 * @num: parameter
 * Return: void
 */
void print_binary(unsigned int num)
{
	if (num / 2 != 0)
	{
		print_binary(num / 2);
	}
	putchar(num % 2 == 0 ? '0' : '1');
}
/**
 * _printf - works like printf
 * @format: string
 * Return: count
 */
int _printf(const char *format, ...)
{
	va_list args;
	unsigned int value;

	va_start(args, format);
	int count = 0;

	for (const char *p = format; *p != '\0'; p++)
	{
		if (*p == '%')
		{
			p++; /* move past '%'*/
			if (*p == 'd' || *p == 'i') /*handle %d and %i specifiers*/
			{
				int value = va_arg(args, int);

				printf("%d", value);
				count++;
			}
			else if (*p == 'b')
			{
				value = va_arg(args, unsigned int);
				print_binary(value);
				count++;
			}
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



