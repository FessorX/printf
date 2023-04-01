#include "main.h"

/**
 * print_address - prints address of input in hexa format
 *
 * @address: va_list arguments from _printf
 * @f: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int print_address(va_list address, flag *f)
{
	char *str;
	unsigned long int n = va_arg(address, unsigned long int);

	 int count = 0;

	(void)f;

	if (!n)
		return (_puts("(nil)"));
	str = convert(n, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
