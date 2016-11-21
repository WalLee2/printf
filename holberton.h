#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdarg.h>
int _printf(const char *format, ...);
int _putchar(char c);
int print_number(int n);
typedef struct print_a
{
	char *s;
	int (*f)();
} print_a_t;
#endif
