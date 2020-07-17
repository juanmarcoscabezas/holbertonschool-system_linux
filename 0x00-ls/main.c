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
	size_t dir_iterator = 0;
	LS_Struct_t ls_struct;

	ls_struct.directories = get_directories(
		argc, argv, &ls_struct.directories_number);
	ls_struct.options = get_options_list(argc, argv);

	for (
		dir_iterator = 0;
		dir_iterator < ls_struct.directories_number;
		dir_iterator++)
	{
		execution_return = opendir_current_in_argv(
			argv, ls_struct.directories[dir_iterator],
			ls_struct.options, ls_struct.directories_number);
		free(ls_struct.directories[dir_iterator]);
	}
	free(ls_struct.directories);
	return (execution_return);
}

/**
 * opendir_current_in_argv - Opens an user input directory
 * @argv: Application parameters
 * @dir_name: Name of the directory
 * @options: List of options
 * @directories_number: Number of directories
 * Return: 0 on success, 2 otherwise
 */
int opendir_current_in_argv(
	char **argv, char *dir_name, char options, size_t directories_number)
{
	DIR *dir;
	size_t list_index = 0;
	char **dir_list = NULL;
	int execution_return = 0;

	dir = opendir(dir_name);

	if (dir)
	{
		print_dirname_at_start(dir_name, directories_number);
		dir_list = readdir_get_directories(dir, &list_index);
		sort_directories_list_by_name(dir_list, list_index);
		print_directories_with_parameters(dir_list, dir_name, options, list_index);
		print_endofline_at_end(directories_number);
		free(dir_list);
		closedir(dir);
		return (0);
	}
	execution_return = show_error_messages(argv, dir_name, directories_number);
	closedir(dir);
	return (execution_return);
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

/**
 * print_directories_with_parameters - Prints the files in a directory
 * with the parameters
 * @dir_list: Files/directories inside the current directory
 * @dir_name: Current directory name
 * @options: The user options
 * @list_index: Size of the @dir_list
 * Return:
 */
void print_directories_with_parameters(
	char **dir_list, char *dir_name, char options, size_t list_index)
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
		{
			if (dir_list[iterator][0] != '.')
				printf("%s\n", dir_list[iterator]);
		}
		else if (options == 'a')
		{
			printf("%s  ", dir_list[iterator]);
		}
		else
		{
			if (dir_list[iterator][0] != '.')
				printf("%s  ", dir_list[iterator]);
		}

		free(dir_list[iterator]);
	}
}
