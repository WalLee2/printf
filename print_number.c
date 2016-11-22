#include "holberton.h"
#include <stdarg.h>
/**
 *_puts - a function that prints out the string followed by a new line.
 *@str: a variable that contains the string.
 *
 */
void _puts(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
	{
		_putchar(str[i]);
	}
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
