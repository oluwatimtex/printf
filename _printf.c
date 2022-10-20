#include "main.h"

/**
 * _printf - prints the characters given to it but
 * takes note of some format specifiers
 * @format: This is the string that's going to be checked through
 *
 * Return: An integer -- the length of the string
 */

int _printf(const char *format, ...)
{
	va_list char_list;
	int l;

	l = 0;
	va_start(char_list,  format);

	while (*(format + l) != '\0')
	{
		if (*(format + l) == '%')
		{
			if (*(format + l + 1) == 'c')
			{
				_putchar(va_arg(char_list, char));
			}
			else if (*(format + l + 1) == 's')
			{
				char *str;
				int i;

				i = 0;
				str = va_arg(char_list, char*);
				while (*(str + i) != '\0')
				{
					_putchar(*(str + i));
					i++;
				}
			}
			else if (*(format + l + 1) == 'd'
					|| *(format + l + 1) == 'i')
			{
				_putchar('0' + va_args(char_list, int));
			}
			else if (*(format + l + 1) == '%')
				_putchar('%');
			l += 2;
		}
		else
		{
			_putchar(*(format + l));
			l++;
		}
	}
	return (l);
}
