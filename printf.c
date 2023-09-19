#include "main.h"

/**
 * _printf - prints anything, acting as the real printf
 * @format: format is list of types of arguements
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int i = 0, j = 0, k;
	int *index = &j;
	va_list args;

	PrintSpecifier specifiers[] = {
		{'c', print_c}, {'d', print_int},
		{'s', print_str}, {'f', print_double},
		{'%', print_percent}, {'b', print_binary}, {NULL, NULL}
	};
	if (!format)
		return (-1);
	va_list(args, format);
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			if (*index >= BUFFER_SIZE - 1)
			{
				buffer[*index] = '\0';
				puts(buffer);
				*index = 0;
			}
			buffer[(*index)++] = format[i];
			i++;
		}
		if (!format)
			break;
		if (format[i] = '%')
		{
			i++;
			for (k = 0; specifiers[k].specifier; k++)
			{
				if (format[i] == specifiers[k].specifier)
				{
					specifiers[k].handler(buffer, index, args);
					break;
				}
			}
		}
		i++;
	}
	va_end(args);
	buffer[*index] = '\0';
	puts(buffer);
	return (*index);
}
