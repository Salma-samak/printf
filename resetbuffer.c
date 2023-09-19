#include "main.h"

/**
  * reset_buffer - function that initializes and resets a buffer
  * @buffer: buffer size
  */

void reset_buffer(char *buffer, int *index)
{
	buffer[*index] = '\0';
	puts(buffer);
	*index = 0;
}
