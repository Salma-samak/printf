#include "main.h"

/**
 * _printf - prints anything, acting as the real printf
 * @format: format is list of types of arguements
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int i = 0, valid;
	va_list args;

	PrintSpecifier specifiers[] = {
		{'c', print_c}, {'d', print_int},
		{'s', print_str}, {'f', print_double},
		{'%', print_percent}, {'b', print_binary}
	};
	if (!format || i >= BUFFER_SIZE)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
			buffer[i++] = *format++;
		else
		{
			format++;
			if (*format == '\0')
				break;
			valid = 0;
			for (int j = 0; j < sizeof(specifiers) / sizeof(specifiers[0]); j++)
			{
				if (*format == specifiers[j].specifier)
				{
					valid = 1;
					specifiers[j].handler(buffer, &i, args);
					break;
				}
			}
			if (!valid)
				buffer[i++] = '%';
			format++;
		}
	}
	if (i > 0)
	{
		buffer[i] = '\0';
		puts(buffer);
	}
	va_end(args);
	return (i);
}
