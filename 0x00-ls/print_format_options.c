#include "header.h"

/**
 * flag_l - ls flag -l
 * @dir_path: Directory path
 * @dir_name: Directory name
 * @dir_list: Directories list
 * @iterator: Actual position in @dir_list
 * Return:
 */
void flag_l(char *dir_path, char *dir_name, char **dir_list, size_t iterator)
{
	struct stat sb;

	dir_path[0] = '\0';
	_strcat(dir_path, dir_name);
	if (dir_name[_strlen(dir_name) - 1] != '/')
	{
		_strcat(dir_path, "/");
	}
	_strcat(dir_path, dir_list[iterator]);
	if (lstat(dir_path, &sb) != -1)
	{
		printf("%ld bytes ", sb.st_size);
	}
}

void flag_a(
	char **dir_list,
	char *dir_path,
	char *dir_name,
	size_t iterator,
	LS_Struct_t ls_struct,
	size_t jump)
{
	if (ls_struct.options.flag_l == 1)
		flag_l(dir_path, dir_name, dir_list, iterator);
	if (jump == 1)
		printf("%s\n", dir_list[iterator]);
	else
		printf("%s  ", dir_list[iterator]);
}

void flag_A(
	char **dir_list,
	size_t iterator,
	size_t jump)
{
	if (dir_list[iterator][0] == '.' && _strlen(dir_list[iterator]) == 1)
		return;
	else if (_strlen(dir_list[iterator]) == 2)
	{
		if ((dir_list[iterator][0] == '.') && (dir_list[iterator][1] == '.'))
			return;
	}
	if (jump == 1)
		printf("%s\n", dir_list[iterator]);
	else
		printf("%s  ", dir_list[iterator]);
}
