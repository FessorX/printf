#include "main.h"

/**
 * get_print - Selects a printing function
 * 
 * @s: character specifier
 * Description: The function loops through the struct's array
 * func_arr[] to match the specifier to the function func_arr[1]
 * Return: a pointer to a function, else NULL
 */
int (*get_print(char s))(va_list, flag *)
{
	ph func_arr[] = {
		{'u', print_unsigned},
		{'i', print_int},
		{'d', print_int},
		{'c', print_char},
		{'s', print_string},
		{'S', print_bigS},
		{'b', print_binary},
		{'o', print_octal},
		{'x', print_hex},
		{'X', print_hex_big},
		{'R', print_rot13},
		{'r', print_rev},
		{'p', print_address},
		{'%', print_percent}
		};

	int arr = 14;
	int i;
	for (i = 0; i < arr; i++)
		if (func_arr[i].c == s)
			return (func_arr[i].f);
	return (NULL);
}