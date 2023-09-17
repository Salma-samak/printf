#include "main.h"

/**
 * _printf - prints anything, acting as thr printf provided by the stdio library
 * @format: format is list of types of arguements
 * Return: Printed chars.
 */

int _printf(const char *format, ...)
{
	char buffer[BUFFER_SIZE];
	int i, j, valid_format;
	va_list args;

	specifier_t specifiers[] = {
		{"c", print_c}, {"d", print_int},
		{"f", print_double},{"s", print_str},
		{"b", print_binary}, {"%", print_percent}
	};
	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (*format)
	{
		if (*format != '%')
		{
			if (i < BUFFER_SIZE - 1)
				buffer[i++] = *format;
			else
			{
				buffer[i] = '\0';
				puts(buffer);
				i = 0;
			}
		}
		else
		{
			format++;
			if (*format == '\0')
				break;
			valid_format = 0;
			for (j = 0; j < sizeof(specifiers) / sizeof(specifiers[0]); j++)
			{
				if (*format == specifiers[j].specifier)
				{
					valid_format = 1;
					specifiers[j]._specifiers(buffer, &i, args);
					break;
				}
			}
			if (!valid_format)
			{
				if (i < BUFFER_SIZE - 1)
				{
					buffer[i++] = '%';
					buffer[i++] = *format;
				}
				else
				{
					buffer[i] = '\0';
					puts(buffer);
					i = 0;
					buffer[i++] = '%';
					buffer[i++] = *format;
				}
			}
		}
		format++;
	}
	if (i > 0)
	{
		buffer[i] = '\0';
		puts(buffer);
	}
	va_end(args);
	return (i);
}
