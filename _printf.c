#include "main.h"
#include <stdarg.h>
#include <unistd.h>
#include <stdio.h>
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
	int count = 0, i;
	char c, *s;
	va_list args;
	va_start(args, format);

	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
				case 'c':
					c = va_arg(args, int);
					count += putchar(c);
					break;
				case 's':
					s = va_arg(args, char *);
					count += printf("%s", s);
					break;
					
				case '%':
					count += putchar('%');
					break;
					
				default:
					break;
			}
		}
		else
		{
			count += putchar(format[i]);
		}
	}
	va_end(args);
	return count;
}