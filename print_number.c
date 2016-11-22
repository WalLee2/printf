#include "holberton.h"
#include <stdarg.h>
/**
 *checkformatter - checks to see if the identifier is equal to
 *what the array of structs is checking for and pointing to the correct
 *function
 *@args: The list of arguments taken in with different data types
 *@print_a: The array that contains the struct
 *@format: Specifies whcih identifier it's going to be
 *Return: either 0 if none of the identifiers match, chars if it does match
 */
int checkformatter(va_list args, print_a_t print_a[], char format)
{
	int j, chars;

	chars = 0;
	for (j = 0; j < 5; j++)
	{
		if (*print_a[j].s == format)
			chars += (print_a[j].f(args));
		return (chars);
	}
	return (0);

}
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
	if (p == '%')
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
