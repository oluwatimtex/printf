#include "main.h"
#include <stdlib.h>

/**
 * _printf - prints anything
 * @format: list of argument types passed to the function
 *
 * Return: int
 */
int _printf(const char *format, ...)
{
	int i, count = 0;
	
	va_list valist;
	va_start(valist, format);

	for (i = 0; format[i] !='\0')
	{
		if (format[i] != '%')
        	{
			count += _putchar(format[i]);
			i++;
		}
		else if (format[i] == '%' && format [i + 1] != ' ')
        	{
            		switch (format[i + 1])
            		{
                		case 'c':
                    		count += print_char(va_arg(valist, int));
                    		break;
                		case 's':
                    		count += print_strings(va_arg(valist, char *));
                    		break;
                		case '%':
                    		count += _putchar('%');
                    		break;
			}
			i += 2; //exit sepicifier
		}
	}
	va_end(valist);

	return (count);
}
