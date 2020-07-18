#include "header.h"

void print_directories(LS_Struct_t ls_struct)
{
	size_t iterator;

	for (
		iterator = 0;
		iterator < ls_struct.directories_number;
		iterator++)
	{
		get_files_in_dir(
			ls_struct.directories[iterator],
			ls_struct);
		free(ls_struct.directories[iterator]);
	}
}

void print_files(LS_Struct_t ls_struct)
{
	size_t iterator;
	size_t jump = 0;

	if (ls_struct.options == '1' || ls_struct.options == 'l')
		jump = 1;

	for (
		iterator = 0;
		iterator < ls_struct.files_number;
		iterator++)
	{
		printf("%s", ls_struct.files[iterator]);
		if (jump == 1)
			printf("\n");
		else
			printf("  ");
		free(ls_struct.files[iterator]);
	}
	if (ls_struct.files_number > 0)
	{
		if (jump == 0)
			printf("\n");
		if (ls_struct.directories)
			printf("\n");
	}
}

void print_errors_access(LS_Struct_t ls_struct)
{
	size_t iterator;

	for (
		iterator = 0;
		iterator < ls_struct.error_access_number;
		iterator++)
	{
		fprintf(stderr, "hls: cannot access %s: No such file or directory\n", ls_struct.error_access[iterator]);
		free(ls_struct.error_access[iterator]);
	}
}

void print_errors_open(LS_Struct_t ls_struct)
{
	size_t iterator;

	for (
		iterator = 0;
		iterator < ls_struct.error_open_number;
		iterator++)
	{
		fprintf(stderr, "hls: cannot open %s: Permission denied\n", ls_struct.error_open[iterator]);
		free(ls_struct.error_open[iterator]);
	}
}