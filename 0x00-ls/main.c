#include "header.h"

/**
 * main - Entry point
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	return (execute(argc, argv));
}

/**
 * execute - Execute's opendir
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
int execute(int argc, char **argv)
{
	int execution_return = 0;
	LS_Struct_t ls_struct;

	ls_struct.directories = NULL;
	ls_struct.files = NULL;
	ls_struct.error_access = NULL;
	ls_struct.error_open = NULL;
	ls_struct.directories_number = 0;
	ls_struct.files_number = 0;
	ls_struct.error_access_number = 0;
	ls_struct.error_open_number = 0;
	ls_struct.options = '\0';

	ls_struct.options = get_options_list(argc, argv);
	ls_struct = get_arguments(argc, argv, ls_struct);

	print_errors_access(ls_struct);
	print_files(ls_struct);
	print_directories(ls_struct);
	print_errors_open(ls_struct);
	free_struct(ls_struct);
	return (execution_return);
}
