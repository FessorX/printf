#include "main.h"

/**
 * convert - converts number and base into string
 *
 * @num:  number
 * @base: base
 * @case: Hexadecimal flag (1 = lowercase)
 * Return: pointer to result string
 */
char *convert(unsigned long int num, int base, int lcase)
{
	static char *rep;
	static char buffer[50];
	char *ptr = &buffer[49];

	rep = (lcase) ? "0123456789abcdef" : "0123456789ABCDEF";
	*ptr = '\0';

	do {
		*--ptr = rep[num % base];
		num /= base;
	} while (num != 0);

	return (ptr);
}
