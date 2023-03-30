#include "main.h"
/**
 * get_flag - turns on flags if _printf finds any
 * 
 * @s: character specifier
 * @f: pointer to the struct flags
 *
 * Return: 1 if turned on, else 0
 */
int get_flag(char s, flag *f)
{
	int i = 0;
	switch (s)
	{
		case '+':
			f->plus = 1;
			i = 1;
			break;
		case ' ':
			f->space = 1;
			i = 1;
			break;
		case '#':
			f->hash = 1;
			i = 1;
			break;
	}
	return (i);
}