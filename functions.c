#include "main.h"

/**
 * print_c - print character
 * @buffer: character
 * @index: int
 * @args: va_list passed to function
 */

void print_c(char *buffer, int *index, va_list args)
{
	char c = va_arg(args, int);

	if (*index < BUFFER_SIZE - 1)
	{
		buffer[(*index)++] = c;
	}
	else
	{
		buffer[*index] = '\0';
		puts(buffer);
		*index = 0;
		buffer[(*index)++] = c;
	}
}

/**
 * print_str - print strings
 * @buffer: character
 * @index: int
 * @args: va_list passed to function
 */

void print_str(char *buffer, int *index, va_list args)
{
	char *str = va_arg(args, char *);
	int length, i;

	for (length = 0; str[length] != '\0'; length++)
		;
	for (i = 0; i < length; i++)
	{
		if (*index < BUFFER_SIZE - 1)
		{
			buffer[(*index)++] = str[i];
		}
		else
		{
			buffer[*index] = '\0';
			puts(buffer);
			*index = 0;
			buffer[(*index)++] = str[i];
		}
	}
}

/**
 * print_int - print integers
 * @buffer: character
 * @index: int
 * @args: va_list passed to function
 */

void print_int(char *buffer, int *index, va_list args)
{
	int i = va_arg(args, int);

	*index = snprintf(buffer + *index, BUFFER_SIZE - *index, "%d", i);
	if (*index >= BUFFER_SIZE - 1)
	{
		buffer[*index] = '\0';
		puts(buffer);
		*index = 0;
	}
}

/**
 * print_double - print double
 * @buffer: character
 * @index: integer
 * @args: va_list passed to function
 */

void print_double(char *buffer, int *index, va_list args)
{
	double i = va_arg(args, double);

	*index = snprintf(buffer + *index, BUFFER_SIZE - *index, "%.2f", i);
	if (*index >= BUFFER_SIZE - 1)
	{
		buffer[*index] = '\0';
		puts(buffer);
		*index = 0;
	}
}

/**
 * print_percent - prints percentage sign
 * @buffer: character
 * @index: integer
 * @args: va_list passed to function
 */

void print_percent(char *buffer, int *index, __attribute__((unused))va_list args)
{
	if (*index < BUFFER_SIZE - 1)
	{
		buffer[(*index)++] = '%';
	}
	else
	{
		buffer[*index] = '\0';
		puts(buffer);
		*index = 0;
		buffer[(*index)++] = '%';
	}
}
