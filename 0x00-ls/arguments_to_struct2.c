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
		ls_struct = set_directories(argv, iterator, ls_struct);
	else if (lstat(argv[iterator], &sb) == 0
	&& !S_ISDIR(sb.st_mode))
		ls_struct = set_files(argv, iterator, ls_struct);
	else if (lstat(argv[iterator], &sb) == -1 && !(sb.st_mode & S_IRUSR))
		ls_struct = set_errors_access(argv, iterator, ls_struct);
	else
		ls_struct = set_errors_open(argv, iterator, ls_struct);
	closedir(dir);
	return (ls_struct);
}
