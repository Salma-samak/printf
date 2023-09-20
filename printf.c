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
		{'c', print_char}/*, {'d', print_double}, {'s', print_str}, {'i', print_int},
		{'u', print_unint}, {'%', print_percent}, {'x', print_hex}, {'X', print_HEX},
		{'o', print_octa}, {'b', print_binary}, {'p', print_point}, {'r', print_rot},
		{'R', print_ROT}, {'\0', NULL}*/
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
