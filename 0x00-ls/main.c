#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>

void execute(int, char **);

/**
 * main - Entry point
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	execute(argc, argv);
	return (0);
}

/**
 * execute - Execute's opendir
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
void execute(int argc, char **argv)
{
	DIR *dir;
	struct dirent *read;

	if (argc <= 1)
	{
		dir = opendir(".");
		while ((read = readdir(dir)) != NULL)
		{
			printf("%s\n", read->d_name);
		}
	}
	else
	{
		dir = opendir(argv[1]);
		while ((read = readdir(dir)) != NULL)
		{
			printf("%s\n", read->d_name);
		}
	}
	closedir(dir);
}
