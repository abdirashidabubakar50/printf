#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _putchar - helper function to create a character
 * @c: the character to be printed
 * Return: returns the character printed
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _printf - a function that works like print
 * @format: the format string
 * Return: the printed characters excludi9ng the null byte
 */
int _printf(const char *format, ...)
{
	char ch;
	int i, j, printed = 0;

	if (!format)
		return -1;

	va_list list;
	va_start(list, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			printed++;
		}
		else
		{
			i++;
			ch = format[i];

			if (ch == 'c')
			{
				char c = va_arg(list, int);

				_putchar(c);
				printed++;
			}
			else if (ch == 's')
			{
				char *str = va_arg(list, char *);

				if (str != NULL)
				{
					for (j = 0; str[j] != '\0'; j++)
					{
						_putchar(str[j]);
						printed++;
					}
				}
			}
			else if (ch == '%')
			{
				_putchar(ch);
				printed++;
			}
		}
	}
	va_end(list);
	return (printed);
}
