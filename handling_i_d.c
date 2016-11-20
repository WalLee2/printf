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
int print_char(va_list args)
{
	char *j;
	j = va_arg(args, char *);
	_putchar(*j);
	return (0);
}
int print_int(va_list args)
{
	int *n;

	n = va_arg(args, int *);
	print_number(*n);
	return (0);
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
		{"c", print_char},
		{"i", print_int},
		{"d", print_int}
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
			while (j < 4)
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
