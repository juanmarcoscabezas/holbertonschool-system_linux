#include "header.h"

/**
 * get_directories - Gets the directories list
 * @argc: Application parameters length
 * @argv: Application parameters
 * @directories_number: Number of params
 * Return: Then list of directories
 */
char **get_directories(int argc, char **argv, size_t *directories_number)
{
	int iterator;
	char **directories = NULL;
	size_t directories_index = 0;

	for (iterator = 1; iterator < argc; iterator++)
	{
		if (argv[iterator][0] != '-')
		{
			directories = realloc(directories,
								  sizeof(char *) * (directories_index + 1));
			directories[directories_index] = strdup(argv[iterator]);
			directories_index++;
		}
		if (argv[iterator][0] == '-' && strlen(argv[iterator]) == 1)
		{
			directories = realloc(directories,
								  sizeof(char *) * (directories_index + 1));
			directories[directories_index] = strdup(argv[iterator]);
			directories_index++;
		}
		if (strlen(argv[iterator]) == 2)
		{
			if (argv[iterator][0] == '-' && argv[iterator][1] == '-')
			{
				directories = realloc(directories,
									  sizeof(char *) * (directories_index + 1));
				directories[directories_index] = strdup(".");
				directories_index++;
			}
		}
	}
	if (directories_index == 0)
	{
		directories = realloc(directories, sizeof(char *) * (directories_index + 1));
		directories[directories_index] = strdup(".");
		directories_index++;
	}
	*directories_number = directories_index;
	return (directories);
}
