#include "main.h"
/**
 * _printf - printf function
 *
 * @format: const char pointer
 * Return: len
 */
int _printf(const char *format, ...)
{
	const char *p;
	va_list args;
	int (*printfunction)(va_list, flag *);
	flag flags = {0, 0, 0};

	int count = 0;

	va_start(args, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (get_flag(*p, &flags))
				p++;
			printfunction = get_print(*p);
			count += (printfunction)
				? printfunction(args, &flags)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(args);
	return (count);
}
