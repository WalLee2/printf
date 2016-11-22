#include "holberton.h"
#include <unistd.h>
#include <stdarg.h>
/**
 *print_str - a function that prints out a string
 *@args: a list of all the arguments that the function will take
 *Return: The number of characters
 */
int print_str(va_list args)
{
	char *j;
	int i, chars;

	chars = 0;
	j = va_arg(args, char *);
	if (j == NULL)
		j = "(null)";
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
 *print_char - a funciton that prints out a character
 *@args: a variable that takes in a varrying amount of function arguments
 *Return: Zero is returned
 */
int print_char(va_list args)
{
	char j;

	j = va_arg(args, int);
	_putchar(j);
	return (1);
}
/**
 *print_int - A function that prints out the integer
 *@args: a variable that takes in a varrying amount of function arguments
 *Return: The character
 */
int print_int(va_list args)
{
	int n, chars;

	n = va_arg(args, int);
	chars = print_number(n);
	return (chars);
}
/**
 *_printf - Remaking the printf function in the standard input output library
 *@format: Detects what format the arguments come in as
 *Return: The number of characters to be printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i, j, chars;
	print_a_t print_a[] = {
		{"s", print_str},
		{"c", print_char},
		{"%", print_per},
		{"i", print_int},
		{"d", print_int},
		{NULL, NULL}
	};
	va_start(args, format);

	chars = i = 0;
	if (format == NULL || args == NULL)
		return (chars);
	while (format != NULL && format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			j = 0;
			while (j < 5)
			{
				if (*print_a[j].s == format[i])
				{
					chars += (print_a[j].f(args));
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
