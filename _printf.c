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
	char ch, *str,c;
	int i, j, printed = 0, numb, divisor, digit;

	va_list list;
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
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
			if (ch == 'c'){
				c = va_arg(list, int);
				_putchar(c);
				printed++;
			}
			else if (ch == 's')
			{
				str = va_arg(list, char *);
				if (str == NULL)
				{
					va_end(list);
					return (-1);
				}
				if (str != NULL){
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
			else if( ch == 'd' || ch == 'i')
			{
				numb = va_arg(list, int);
				if (numb < 0)
				{
					_putchar('-');
					printed++;
					numb = -numb;
				}
				divisor = 1;
				while(numb / divisor > 9)
				{
					divisor *= 10;
				}
				while (divisor != 0)
				{
					digit = numb / divisor;
					_putchar(digit);
					numb = numb % divisor;
					divisor /= 10;
				}
			}
			else 
			{
				_putchar('%');
				_putchar(ch);
				printed += 2;
			}
		}
	}
	va_end(list);
	return (printed);
}