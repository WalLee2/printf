#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *
 *
 *
 */
int print_str(va_list args)
{
	char *j;
	int i, chars;

	j = va_arg(args, char *);
	if (j == NULL)
		return (-1);
	i = 0;
	while (j[i] != '\0')
	{
		_putchar(j[i]);
		i++;
		chars++;
	}
	return (chars);
}
/**
 *
 *
 *
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, chars;
	print_a_t print_a[] = {
		{"s", print_str},
		{"c", print_char}
	};
	va_start(args, format);

	if (format == NULL)
	{
		write(1, "Error\n", 6);
		return (-1);
	}
	i = chars = 0;
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			while (j < 2)
			{
				if (*print_a[j].s == format[i])
				{
					chars += print_a[j].f(args);
				}
				j++;
			}
		}
		else
		{
			_putchar(format[i]);
			chars++;
		}
		i++;
	}
	va_end(args);
	return (chars);
}
