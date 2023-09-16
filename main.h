#ifndef main_h
#define main_h

#include <stdarg.h>
#include <stdio.h>
#include <stdbool.h>

#define BUFFER_SIZE 1024

/**
 * struct formats - Struct operators
 *
 * @specifier: Char
 * @specifiers: The function associated
 */

typedef struct specifier
{
	char specifier;
	void (*specifiers)(char *buffer, int *index, va_list args);
} specifier_t;

int _printf(const char *format, ...);

void print_c(char *buffer, int *index, va_list args);
void print_str(char *buffer, int *index, va_list args);
void print_int(char *buffer, int *index, va_list args);
void print_double(char *buffer, int *index, va_list args);
void print_binary(char *buffer, int *index, va_list args);
void print_percent(char *buffer, int *index, va_list args);

#endif
