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
 * @option: The actual option selected
 * @num_errors: Number of errors
 * Return:
 */
void print_endofline_at_end(
	size_t directories_number, char option, size_t num_errors)
{
	static size_t actual_number = 1;

	if (option != 'l' && option != '1')
	{
		if (
			directories_number > 1 && actual_number < directories_number - num_errors)
			printf("\n\n");
		else
			printf("\n");
		actual_number++;
		return;
	}
	else if (
		directories_number > 1 && actual_number < directories_number - num_errors)
		printf("\n");

	actual_number++;
}
