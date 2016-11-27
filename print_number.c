#include "holberton.h"
#include <stdarg.h>
#include <stdio.h>
/**
 *check_formatter - Function that checks if the character pointer is NULL, and
 *if it is NULL, it will return the number of charaters which is 0. Verifies
 *if the first character is a "%", if it is, move to the next character,
 *checks the array of structs, if they match, run the function. If not, print
 *the % and the character.
 *@args: a pointer that is initiated by va_list
 *@format: a pointer variable that points to what's being passed to _printf
 *@print_a: The array of structs that is initated in the _printf function
 *Return: The number of characters that was printed
 */
int check_formatter(va_list args, const char *format, print_a_t print_a[])
{
	int formatter, i, j, chars;

	formatter = i = j = chars = 0;
	for (i = 0; format != NULL && format[i] != '\0'; i++)
	{
		if (format[i] == '%')
		{
			i++;
			for (j = 0; j < 7; j++)
			{
				if (print_a[j].s == format[i])
				{
					chars += (print_a[j].f(args));
					formatter = 1;
				}
			}
			if (formatter == 0)
			{
				i--;
				_putchar(format[i]);
				i++;
				_putchar(format[i]);
				chars += 2;
			}
		}
		else
		{
			_putchar(format[i]);
			chars++;
		}
	}
	return (chars);
}
/**
 *print_rev - a function that prints the string in reverse
 *@s: a variable that points to the first address in memory of
 *the string
 */
int print_rev(va_list args)
{
	char *s;
	int i, chars;

	chars = 0;
	s = va_arg(args, char *);
	for (i = 0; s[i] != '\0'; i++)
		;
	for (; i != 0; i--)
	{
		_putchar(s[i - 1]);
		chars++;
	}
	return (chars);
}
/**
 *print_rot13 - a function that will print a string in rot13
 *@o: a pointer variable that points to the first address in memory
 *of the string being observed
 *Return: The new string after being modified
 */
int print_rot13(va_list args)
{
	char *o;
	int i, chars;

	printf("I'm here");
	i = chars = 0;
	o = va_arg(args, char*);
	while (o[i] != '\0')
	{
		printf("In the while loop");
		if ((o[i] >= 'a' && o[i] <= 'z') ||
		    (o[i] >= 'A' && o[i] <= 'Z'))
		{
			printf("In the if conditional");

			while ((o[i] >= 'a' && o[i] <= 'm') ||
			       (o[i] >= 'A' && o[i] <= 'M'))
			{
				printf("I'm in the first while loop");
				o[i] += 13;
				_putchar (o[i]);
				chars++;
				i++;
			}
			printf("I'm done with the first while loop");
			while ((o[i] >= 'n' && o[i] <= 'z') ||
			       (o[i] >= 'N' && o[i] <= 'Z'))
			{
				printf("I'm in the second while loop");
				o[i] -= 13;
				_putchar (o[i]);
				chars++;
				i--;
			}
			printf("I'm done with the second while loop");
		}
		else
		{
			i++;
		}
	}
	return (chars);
}
/**
 *print_per - a function that accounts for %% as an input
 *@p: A parameter that stores a % and prints it
 *Return: Return the % character
 */
int print_per(int p)
{
	p = '%';
	_putchar(p);
	return (1);
}
/**
 * print_number - A function that prints out numbers
 * @n: number to print
 * Return: the number
 */
int print_number(int n)
{
	int sign, ten, chars;

	chars = 0;
	sign = 1;
	ten = 1000000000;
	if (n > 0)
	{
		n = n * -1;
		sign = sign * -1;
	}
	if (n != 0)
	{
		while (n / ten == 0)
		{
			ten = ten / 10;
		}
		if (sign == 1)
		{
			_putchar('-');
			chars++;
		}
		while (ten >= 1)
		{
			_putchar(-(n / ten) + '0');
			chars++;
			n = n % ten;
			ten = ten / 10;
		}
	}
	else
	{
		_putchar('0');
		chars++;
	}
	return (chars);
}
