#include "main.h"

/**
 * _printf - prints anything, acting as the real printf
 * @format: format is list of types of arguements
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	int i = 0, j, valid, len = 0;
	va_list args;

	PrintSpecifier specifiers[] = {
		{'c', print_c}, {'i', print_int},
		{'s', print_str}, {'d', print_double},
		{'%', print_percent}, {'b', print_binary}
	};
	va_start(args, format);
	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	while (format[i] != '\0')
	{
		j = 0, valid = 0;
		while (specifiers[j].specifier != NULL)
		{
			if (format[i] == '%' && format[i + 1] == specifiers[j].specifier[1])
			{
				len += specifiers[j].handler(args);
				i = i + 2;
				valid = 1;
				btreak;
			}
			j++;
		}
		if (!valid)
		{
			char char_to_print[2] = {format[i], '\0'};
			puts(char_to_print);
			len++;
			i++;
		}
	}
	va_end(args);
	return (len);
}
