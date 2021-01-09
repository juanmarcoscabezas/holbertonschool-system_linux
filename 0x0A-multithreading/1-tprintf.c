#include "multithreading.h"

/**
 * tprintf - uses the printf family to print out a given formatted string
 * @format: Formated string
 * Return: 0
 */
int tprintf(char const *format, ...)
{
	va_list args;
	pthread_t self;

	self = pthread_self();
	setbuf(stdout, NULL);
	va_start(args, format);
	printf("[%lu] ", self);
	vprintf(format, args);
	va_end(args);
	return (0);
}
