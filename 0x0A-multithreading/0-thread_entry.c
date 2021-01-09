#include "multithreading.h"

/**
 * thread_entry - serve as the entry point to a new thread
 * @arg: holds the address of a string that must be printed
 * and followed by a new line
 * Return: void
 */
void *thread_entry(void *arg)
{
	setbuf(stdout, NULL);
	printf("%s\n", (char *) arg);
	pthread_exit(NULL);
}
