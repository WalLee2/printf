#ifndef HOLBERTON_H
#define HOLBERTON_H
#include <unistd.h>
#include <stdarg.h>
/**
 *struct print_a - A struct that has a pointer character and a pointer
 *to a function
 *@s: a character pointer
 *@f: a function pointer
 */
typedef struct print_a
{
	char *s;
	int (*f)();
} print_a_t;
int checkformatter(va_list args, print_a_t print_a[], char format);
int _printf(const char *format, ...);
int _putchar(char c);
int print_number(int n);
void a_struct(void);
int print_per(int p);
void _puts(char *str);
#endif
