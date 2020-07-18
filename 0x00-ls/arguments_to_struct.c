#include "header.h"

/**
 * get_directories - Gets the directories list
 * @argc: Application parameters length
 * @argv: Application parameters
 * @dir_number: Number of params
 * Return: Then list of directories
 */
LS_Struct_t get_arguments(int argc, char **argv, LS_Struct_t ls_struct)
{
	DIR *dir;
	int iterator;

	for (iterator = 1; iterator < argc; iterator++)
	{
		if (
			argv[iterator][0] != '-' || (argv[iterator][0] == '-' && strlen(argv[iterator]) == 1))
		{
			dir = opendir(argv[iterator]);
			if (dir)
			{
				ls_struct.directories = set_list(argv, ls_struct.directories, ls_struct.directories_number, iterator);
				ls_struct.directories_number++;
			}
			if (errno == 20)
			{
				ls_struct.files = set_list(argv, ls_struct.files, ls_struct.files_number, iterator);
				ls_struct.files_number++;
			}
			if (errno == 2)
			{
				ls_struct.error_access = set_list(argv, ls_struct.error_access, ls_struct.error_access_number, iterator);
				ls_struct.error_access_number++;
			}
			if (errno == 13)
			{
				ls_struct.error_open = set_list(argv, ls_struct.error_open, ls_struct.error_open_number, iterator);
				ls_struct.error_open_number++;
			}
			errno = 0;
			closedir(dir);
		}
		if (strlen(argv[iterator]) == 2)
		{
			if (argv[iterator][0] == '-' && argv[iterator][1] == '-')
			{
				ls_struct.directories = realloc(ls_struct.directories,
									  sizeof(char *) * (ls_struct.directories_number + 1));
				ls_struct.directories[ls_struct.directories_number] = strdup(".");
				ls_struct.directories_number++;
			}
		}
	}
	if (ls_struct.directories_number == 0 && ls_struct.files_number == 0 && ls_struct.error_access_number == 0 && ls_struct.error_open_number == 0)
	{
		ls_struct.directories = realloc(ls_struct.directories, sizeof(char *) * (ls_struct.directories_number + 1));
		ls_struct.directories[ls_struct.directories_number] = strdup(".");
		ls_struct.directories_number++;
	}
	return (ls_struct);
}

char **set_list(char **argv, char **list, size_t list_index, int iterator)
{
	list = realloc(list,
						  sizeof(char *) * (list_index + 1));
	list[list_index] = strdup(argv[iterator]);
	return (list);
}
