#include "header.h"

/**
 * print_dirname_at_start - Prints the dirname
 * @dir_name: The directory name
 * @directories_number: The number of direcories
 * Return:
 */
void print_dirname_at_start(char *dir_name, int directories_number)
{
	if (directories_number > 1)
	{
		printf("%s:\n", dir_name);
	}
}

/**
 * print_endofline_at_end - Prints the an end of line
 * @directories_number: The number of direcories
 * Return:
 */
void print_endofline_at_end(char directories_number)
{
	if (directories_number > 1)
		printf("\n\n");
	else
		printf("\n");
}
