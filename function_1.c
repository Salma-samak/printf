#include "main.h"

/**
 * print_unsignedint - prints unsigned int
 * @buffer: character
 * @index: int
 * @args: va_list passed to function
 */

void print_unsignedint(char *buffer, int *index, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char num_buffer[32];
	int i, length = snprintf(num_buffer, sizeof(num_buffer), "%u", n);

	for (i = 0; i < length; i++)
	{
		if (*index < BUFFER_SIZE - 1)
			buffer[(*index)++] = num_buffer[i];
		else
		{
			buffer[*index] = '\0';
			puts(buffer);
			*index = 0;
			buffer[(*index)++] = num_buffer[i];
		}
	}
}

/**
 * print_hex - prints hexadecimal value
 * @buffer: character
 * @index: int
 * @args: va_list passed to function
 */

void print_hex(char *buffer, int *index, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex_buffer[32];

	snprintf(hex_buffer, sizeof(hex_buffer), "%x", n);
	for (int i = 0; hex_buffer[i] != '\0'; i++)
	{
		if (*index >= BUFFER_SIZE - 1)
		{
			reset_buffer(buffer, index);
		}
		buffer[(*index)++] = hex_buffer[i];
	}
}

/**
 * print_HEX - prints HEXADECIMAL values
 * @buffer: character
 * @index: int
 * @args: va_list passed to function
 */

void print_HEX(char *buffer, int *index, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	char hex_buffer[32];

	snprintf(hex_buffer, sizeof(hex_buffer), "%X", n);
	for (int i = 0; hex_buffer[i] != '\0'; i++)
	{
		if (*index >= BUFFER_SIZE - 1)
		{
			reset_buffer(buffer, index);
		}
		buffer[(*index)++] = hex_buffer[i];
	}
}

/**
 * print_
