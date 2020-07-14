#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>

int execute(int, char **);
int opendir_loop(char **argv, char *dir_name);
int search_options(char *);
char *error_message(int);

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

	if (argc <= 1)
	{
		execution_return = opendir_loop(argv, ".");
	}
	for (argc_iterator = 1; argc_iterator < argc; argc_iterator++)
	{
		if (search_options(argv[argc_iterator]) == 0) {
			execution_return = opendir_loop(argv, argv[argc_iterator]);
		}
	}
	return (execution_return);
}

int search_options(char *option) {
	int opt_iterator;

	char *options[1] = {
		"-l"};

	if (option[0] == '-') {
		for (opt_iterator = 0; opt_iterator < 1; opt_iterator++)
		{
			if (strcmp(options[opt_iterator], option) == 0) {
				printf("We got the option %s\n", options[opt_iterator]);
				return (1);
			}
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

int opendir_loop(char **argv, char *dir_name)
{
	DIR *dir;
	struct dirent *read;

	dir = opendir(dir_name);

	if (dir)
	{
		printf("%s:\n", dir_name);

		while ((read = readdir(dir)) != NULL)
		{
			printf("%s ", read->d_name);
		}
		printf("\n\n");
		closedir(dir);
		return (0);
	}
	if (errno == 20) {
		printf("%s\n", dir_name);
		return (0);
	}
	fprintf(stderr, "%s: %s '%s': ", argv[0], error_message(errno), dir_name);
	perror("");
	closedir(dir);
	return (2);
}
