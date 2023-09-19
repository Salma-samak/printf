#include "main.h"

/**
 * print_binary - prints binary numbers
 * @buffer: character
 * @index: integer
 * @args: va_list passed to function
 */

void print_binary(char *buffer, int *index, va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int binary_digits[32];
	int i = 0;

	if (n == 0)
		binary_digits[i++] = 0;
	else
	{
		while (n > 0)
		{
			binary_digits[i++] = n % 2;
			n /= 2;
		}
	}
	while (i > 0)
	{
		char digit = binary_digits[--i] + '0';

		if (*index >= BUFFER_SIZE - 1)
			reset_buffer(buffer, index);
		buffer[(*index)++] = digit;
	}
}
