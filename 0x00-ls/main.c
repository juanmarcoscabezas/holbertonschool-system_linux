#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <time.h>

int execute(int, char **);
int get_opendir_dir_list(char **, char *, char);
int get_options(char *);
char *error_message(int);
int _strcmp_ci(char *, char *);

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
	int argc_iterator;
	int execution_return = 0;
	char options;

	for (argc_iterator = 1; argc_iterator < argc; argc_iterator++)
	{
		if (argv[argc_iterator][0] == '-')
		{
			options = get_options(argv[argc_iterator]);
		}
	}
	if (argc <= 1)
	{
		execution_return = get_opendir_dir_list(argv, ".", options);
	}
	for (argc_iterator = 1; argc_iterator < argc; argc_iterator++)
	{
		if (argv[argc_iterator][0] != '-')
		{
			get_opendir_dir_list(argv, argv[argc_iterator], options);
		}
		// if (get_options(argv[argc_iterator]) == 0)
		// {
		// 	execution_return = get_opendir_dir_list(argv, argv[argc_iterator]);
		// }
	}
	return (execution_return);
}

int get_options(char *option)
{
	int option_iterator;
	size_t flags_iterator;
	int option_length = 0;
	int correct_flag = 0;

	char *flags = "aArStR1l";
	// char flags_in_option[] = "00000000";

	if (option[0] == '-')
	{
		option_length = strlen(option);

		for (option_iterator = 1; option_iterator < option_length; option_iterator++)
		{
			for (flags_iterator = 0; flags_iterator < strlen(flags); flags_iterator++)
			{
				if (flags[flags_iterator] == option[option_iterator])
				{
					correct_flag = 1;
					return(flags[flags_iterator]);
				}
			}
			if (correct_flag == 0)
			{
				printf("The flag %c not exist\n", option[option_iterator]);
				exit(0);
			}
			correct_flag = 0;
		}
	}
	return (0);
}

char *error_message(int error)
{
	char *error_messages[3] = {
		"",
		"cannot access",
		"cannot open directory"};

	/*printf("%d\n", error);*/

	switch (error)
	{
	case 2:
		return (error_messages[1]);
	case 13:
		return (error_messages[2]);
	default:
		return (error_messages[0]);
	}
}

int get_opendir_dir_list(char **argv, char *dir_name, char options)
{
	DIR *dir;
	struct dirent *read;
	size_t list_index = 0, read_index = 0, iterator, jiterator;
	char **dir_list = NULL;
	char *swap_string;
	struct stat sb;
	char dir_path[256];

	dir = opendir(dir_name);

	if (dir)
	{
		printf("%s:\n", dir_name);

		while ((read = readdir(dir)) != NULL)
		{
			dir_list = realloc(dir_list, (list_index + 1) * sizeof(char *));
			dir_list[list_index] = strdup(read->d_name);
			read_index++;
			list_index++;
		}

		for (iterator = 0; iterator < list_index - 1; iterator++)
		{
			for (jiterator = 0; jiterator < list_index - iterator - 1; jiterator++)
			{
				if (_strcmp_ci(dir_list[jiterator], dir_list[jiterator + 1]) > 0)
				{
					swap_string = dir_list[jiterator];
					dir_list[jiterator] = dir_list[jiterator + 1];
					dir_list[jiterator + 1] = swap_string;
				}
			}	
		}

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
				if (stat(dir_path, &sb) != -1) {
					printf("%ld bytes ", sb.st_size);
				}
				printf("statt %s\n", dir_list[iterator]);
			}
			else if (options == '1')
			{
				printf("%s\n", dir_list[iterator]);
			}
			else
			{
				printf("%s ", dir_list[iterator]);
			}
			
			free(dir_list[iterator]);
		}
		free(dir_list);
		
		printf("\n\n");
		closedir(dir);
		return (0);
	}
	if (errno == 20)
	{
		printf("%s\n", dir_name);
		return (0);
	}
	fprintf(stderr, "%s: %s '%s': ", argv[0], error_message(errno), dir_name);
	perror("");
	closedir(dir);
	return (2);
}

/**
 * _strcmp_ci - Compare strings case insensitive
 * Description: This function compare two strings
 * @s1: First string to compare
 * @s2: Second string to compare
 * Return: @n bytes of @src
 */
int _strcmp_ci(char *s1, char *s2)
{
	while (*s1 != '\0' && *s2 != '\0')
	{
		if (tolower(*s1) > tolower(*s2))
			return (tolower(*s1) - tolower(*s2));
		else if (tolower(*s2) > tolower(*s1))
			return ( (tolower(*s2) - tolower(*s1) ) * -1);
		s1++;
		s2++;
	}
	return (0);
}