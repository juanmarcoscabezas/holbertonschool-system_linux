#include "header.h"

/**
 * get_arguments_helper - Helper to extend get_arguments funcionality
 * @argv: Application parameters
 * @iterator: Current position in @argv
 * @ls_struct: Struct that contains all the parameters
 * Return: @ls_struct with the paramters
 */
LS_Struct_t get_arguments_helper(
	char **argv,
	size_t iterator,
	LS_Struct_t ls_struct)
{
	DIR *dir;
	struct stat sb;

	dir = opendir(argv[iterator]);
	if (dir)
	{
		closedir(dir);
		return (set_directories(argv, iterator, ls_struct));
	}
	else if (lstat(argv[iterator], &sb) == 0
	&& S_ISREG(sb.st_mode))
	{
		closedir(dir);
		return (set_files(argv, iterator, ls_struct));
	}
	else if (lstat(argv[iterator], &sb) == 0)
		ls_struct = set_errors_open(argv, iterator, ls_struct);
	else
		ls_struct = set_errors_access(argv, iterator, ls_struct);
	ls_struct.error_value = 2;
	closedir(dir);
	return (ls_struct);
}
