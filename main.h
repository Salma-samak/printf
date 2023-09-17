#ifndef main_h
#define main_h

#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

/**
 * struct specifier - Struct operators
 *
 * @specifier: Char
 * @_specifiers: The function associated
 */

typedef struct
{
	char specifier;
	void (*specifiers)(char *buffer, int *index, va_list args);
} specifier;

int _printf(const char *format, ...);

void print_c(char *buffer, int *index, va_list args);
void print_str(char *buffer, int *index, va_list args);
void print_int(char *buffer, int *index, va_list args);
void print_double(char *buffer, int *index, va_list args);
void print_binary(char *buffer, int *index, va_list args);
void print_percent(char *buffer, int *index, va_list args);

#endif
