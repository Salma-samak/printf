#include "main.h"

/**
 * print_binary - prints binary numbers
 * @buffer: character
 * @index: integer
 * @args: va_list passed to function
 */
void print_binary(char *buffer, int *index, va_list args)
{
	unsigned int i = va_arg(args, unsigned int);
	int j = sizeof(i) * 8 - 1;

	while (j >= 0)
	{
		char digit = (i & (1 << j)) ? '1' : '0';

		if (*index < BUFFER_SIZE - 1)
		{
			buffer[(*index)++] = digit;
		}
		else
		{
			buffer[*index] = '\0';
			puts(buffer);
			*index = 0;
			buffer[(*index)++] = digit;
		}
		j++;
	}
}
