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
	LS_Struct_t ls_struct;
	Flag_t flags;

	ls_struct = initialize_ls(ls_struct);
	ls_struct.options = get_options_list(argc, argv, flags);
	ls_struct = get_arguments(argc, argv, ls_struct);

	print_errors_access(ls_struct);
	print_files(ls_struct);
	print_directories(ls_struct);
	print_errors_open(ls_struct);
	free_struct(ls_struct);
	return (ls_struct.error_value);
}

/**
 * initialize_ls - Initialize the ls_struct
 * @ls_struct: ls struct
 * Return: LS_Struct_t struct
 */
LS_Struct_t initialize_ls(LS_Struct_t ls_struct)
{
	ls_struct.directories = NULL;
	ls_struct.files = NULL;
	ls_struct.error_access = NULL;
	ls_struct.error_open = NULL;
	ls_struct.directories_number = 0;
	ls_struct.files_number = 0;
	ls_struct.error_access_number = 0;
	ls_struct.error_open_number = 0;
	ls_struct.options = initialize_flags(ls_struct.options);
	ls_struct.error_value = 0;
	return (ls_struct);
}

/**
 * initialize_flags - initialize the flags
 * @flags: flags struct
 * Return: Flag_t struct
 */
Flag_t initialize_flags(Flag_t flags)
{
	flags.flag_one = 1;
	flags.flag_a = 1;
	flags.flag_a_u = 1;
	flags.flag_l = 1;
	return (flags);
}
