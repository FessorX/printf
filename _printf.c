#include "main.h"
/**
 * _printf - printf function
 *
 * @format: const char pointer
 * Return: len
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;
	int (*printfunction)(va_list, flag *);
	flag flags = {0, 0, 0};

	int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (ptr = format; *ptr; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*ptr, &flags))
				ptr++;
			printfunction = get_print(*ptr);
			count += (printfunction)
				? printfunction(args, &flags)
				: _printf("%%%c", *ptr);
		} else
			count += _putchar(*ptr);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
