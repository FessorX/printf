#include "main.h"

/**
 * print_int - prints an integer
 * @digits: va_list of arguments from _printf
 * @f: pointer to the struct flag
 *
 * Return: num of char printed to stdout
 */
int print_int(va_list digits, flag *f)
{
	int n = va_arg(digits, int);
	int result = count_digit(n);

	if (f->space == 1 && f->plus == 0 && n >= 0)
		result += _putchar(' ');
	if (f->plus == 1 && n >= 0)
		result += _putchar('+');
	if (n <= 0)
		result++;
	print_number(n);
	return (result);
}

/**
 * print_unsigned - prints an unsigned integer
 * @l: va_list of arguments from _printf
 * @f: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_unsigned(va_list l, flag *f)
{
	unsigned int u = va_arg(l, unsigned int);
	char *str = convert(u, 10, 0);

	(void)f;
	return (_puts(str));
}

/**
 * print_number - helper function that loops through
 * an integer and prints all its digits
 * @n: integer to be printed
 */
void print_number(int n)
{
	unsigned int x;

	if (n < 0)
	{
		_putchar('-');
		x = -n;
	}
	else
		x = n;

	if (x / 10)
		print_number(x / 10);
	_putchar((x % 10) + '0');
}

/**
 * count_digit - returns the number of digits in an integer
 *
 * @i: integer to evaluate
 * Return: number of digits
 */
int count_digit(int i)
{
	unsigned int x = 0;
	unsigned int y;

	if (i < 0)
		y = i * -1;
	else
		y = i;
	while (y != 0)
	{
		y /= 10;
		x++;
	}
	return (x);
}

/**
 * convert - converts number and base into string
 *
 * @num:  number
 * @base: base
 * @lowercase: Hexadecimal flag (1 = lowercase)
 * Return: pointer to result string
 */
char *convert(unsigned long int num, int base, int lowercase)
{
	static char *rep;
	static char buffer[50];
	char *ptr = &buffer[49];

	rep = (lowercase) ? "0123456789abcdef" : "0123456789ABCDEF";
	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
