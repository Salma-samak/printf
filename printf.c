#include "main.h"

/**
 * _printf - prints anything, acting as the real printf
 * @format: format is list of types of arguements
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int i = 0, j, k = 0, *index = &k;
	va_list args;

	PrintSpecifier specifiers[] = {
		{'c', print_c}, {'d', print_int},
		{'s', print_str}, {'f', print_double},
		{'%', print_percent}, {'b', print_binary},
	};
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			if (*index >= BUFFER_SIZE - 1)
				reset_buffer(buffer, index);
			buffer[(*index)++] = format[i];
			i++;
		}
		if (!format[i])
			break;
		if (format[i] == '%')
		{
			i++;
			for (j = 0; specifiers[j].specifier; j++)
			{
				if (format[i] == specifiers[j].specifier)
				{
					specifiers[j].handler(buffer, index, args);
					break;
				}
			}
		}
		i++;
	}
	va_end(args);
	reset_buffer(buffer, index);
	return (*index);
}
