#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>
/**
 * _printf - a function that produces output according to a format
 * @format: character string
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	va_list args;
	char buf[1024];
	int buf_index = 0;

	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					buf[buf_index++] = va_arg(args, int);
					if (buf_index == 1024)
					{
						count += write(1, buf, buf_index);
						buf_index = 0;
					}
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						int str_len = strlen(str);
						if (buf_index + str_len > 1024)
						{
							count += write(1, buf, buf_index);
							buf_index = 0;
						}
						strcpy(&buf[buf_index], str);
						buf_index += str_len;
					}
					break;
				case '%':
					buf[buf_index++] = '%';
					if (buf_index == 1024)
					{
						count += write(1, buf, buf_index);
						buf_index = 0;
					}
					break;
				case 'd':
				case 'i':
					{
						int num = va_arg(args, int);
						int num_len = sprintf(&buf[buf_index], "%d", num);
						buf_index += num_len;
						if (buf_index == 1024)
						{
							count += write(1, buf, buf_index);
							buf_index = 0;
						}
					}
					break;
				case 'u':
					{
						unsigned int num = va_arg(args, unsigned int);
						int num_len = sprintf(&buf[buf_index], "%u", num);
						buf_index += num_len;
						if (buf_index == 1024)
						{
							count += write(1, buf, buf_index);
							buf_index = 0;
						}
					}
					break;
				case 'o':
					{
						unsigned int num = va_arg(args, unsigned int);
						int num_len = sprintf(&buf[buf_index], "%o", num);
						buf_index += num_len;
						if (buf_index == 1024)
						{
							count += write(1, buf, buf_index);
							buf_index = 0;
						}
					}
					break;
				case 'x':
					{
						unsigned int num = va_arg(args, unsigned int);
						int num_len = sprintf(&buf[buf_index], "%x", num);
						buf_index += num_len;
						if (buf_index == 1024)
						{
							count += write(1, buf, buf_index);
							buf_index = 0;
						}
					}
					break;
				case 'X':
					{
						unsigned int num = va_arg(args, unsigned int);
						int num_len = sprintf(&buf[buf_index], "%X", num);
						buf_index += num_len;
						if (buf_index == 1024)
						{
							count += write(1, buf, buf_index);
							buf_index = 0;
						}
					}
			}
		}
	}
}


