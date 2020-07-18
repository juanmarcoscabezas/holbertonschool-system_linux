#include "header.h"

/**
 * opendir_current_in_argv - Opens an user input directory
 * @argv: Application parameters
 * @dir_name: Name of the directory
 * @options: List of options
 * @directories_number: Number of directories
 * Return: 0 on success, 2 otherwise
 */
int get_files_in_dir(
	char *dir_name, LS_Struct_t ls_struct)
{
	DIR *dir;
	size_t list_index = 0;
	char **dir_list = NULL;
	int execution_return = 0;

	dir = opendir(dir_name);

	if (dir)
	{
		print_dirname_at_start(dir_name, ls_struct);
		dir_list = readdir_get_directories(dir, &list_index);
		sort_directories_list_by_name(dir_list, list_index);
		print_directories_with_parameters(
			dir_list,
			dir_name, ls_struct.options,
			list_index,
			ls_struct);
		free(dir_list);
		closedir(dir);
		return (0);
	}
	closedir(dir);
	return (execution_return);
}

/**
 * print_dirname_at_start - Prints the dirname
 * @dir_name: The directory name
 * @directories_number: The number of direcories
 * Return:
 */
void print_dirname_at_start(char *dir_name, LS_Struct_t ls_struct)
{
	if (ls_struct.directories_number > 1 || ls_struct.files_number > 0 || ls_struct.error_access_number > 0 || ls_struct.error_open_number > 0)
		printf("%s:\n", dir_name);
}

/**
 * print_directories_with_parameters - Prints the files in a directory
 * with the parameters
 * @dir_list: Files/directories inside the current directory
 * @dir_name: Current directory name
 * @options: The user options
 * @list_index: Size of the @dir_list
 * @directories_number: Amount of directories
 * @num_errors: Number of errors
 * Return:
 */
void print_directories_with_parameters(
	char **dir_list, char *dir_name,
	char options, size_t list_index,
	LS_Struct_t ls_struct)
{
	size_t iterator;
	char dir_path[256];
	struct stat sb;

	for (iterator = 0; iterator < list_index; iterator++)
	{
		if (options == 'l')
		{
			dir_path[0] = '\0';
			strcat(dir_path, dir_name);
			if (dir_name[strlen(dir_name) - 1] != '/')
			{
				strcat(dir_path, "/");
			}
			strcat(dir_path, dir_list[iterator]);
			if (stat(dir_path, &sb) != -1)
			{
				printf("%ld bytes ", sb.st_size);
			}
			printf("%s\n", dir_list[iterator]);
		}
		else if (options == '1')
			if (dir_list[iterator][0] != '.')
				printf("%s\n", dir_list[iterator]);
			else if (options == 'a')
				printf("%s  ", dir_list[iterator]);
			else if (dir_list[iterator][0] != '.')
				printf("%s  ", dir_list[iterator]);
		free(dir_list[iterator]);
	}
	if (ls_struct.directories_number > 1 || ls_struct.files_number > 0 || ls_struct.error_access_number > 0 || ls_struct.error_open_number > 0)
		printf("\n");
}

/**
 * readdir_get_directories - Gets the directories list
 * @dir: The current oppened directory
 * @list_index: Size of directories_list
 * Return: List of directories
 */
char **readdir_get_directories(DIR *dir, size_t *list_index)
{
	struct dirent *read;
	char **dir_list = NULL;

	while ((read = readdir(dir)) != NULL)
	{
		dir_list = realloc(dir_list, (*list_index + 1) * sizeof(char *));
		dir_list[*list_index] = strdup(read->d_name);
		*list_index = *list_index + 1;
	}
	return (dir_list);
}
