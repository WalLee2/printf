#include "holberton.h"
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
