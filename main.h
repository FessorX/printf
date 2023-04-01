#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flags - struct of flag switches for _printf()
 *
 * @plus: flag for the '+'
 * @space: flag for the ' '
 * @hash: flag for the '#'
 */
typedef struct flags
{
	int plus;
	int space;
	int hash;
} flag;

/**
 * struct printer - struct to choose the right function passed to _printf()
 *
 * @c: format specifier
 * @f: pointer to the correct printing function
 */
typedef struct printer
{
	char c;
	int (*f)(va_list ap, flag *f);
} ph;

int print_int(va_list, flag *f);

void print_number(int n);

int print_unsigned(va_list, flag *f);

int count_digit(int i);

int print_hex(va_list, flag *f);

int print_hex_big(va_list, flag *f);

int print_binary(va_list, flag *f);

int print_octal(va_list, flag *f);

char *convert(unsigned long int num, int base, int lowercase);

int _printf(const char *format, ...);

int (*get_print(char s))(va_list, flag *);

int get_flag(char s, flag *f);

int print_string(va_list, flag *f);

int print_char(va_list, flag *f);

int _putchar(char c);

int _puts(char *str);

int print_rot13(va_list, flag *f);

int print_rev(va_list, flag *f);

int print_bigS(va_list, flag *f);

int print_address(va_list, flag *f);

#endif
