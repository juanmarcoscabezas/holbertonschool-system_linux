#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>

int execute(int, char **);
char *error_message(int);
/**
 * main - Entry point
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
int main(int argc, char **argv)
{
	return(execute(argc, argv));
}

/**
 * execute - Execute's opendir
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: Always 0
 */
int execute(int argc, char **argv)
{
	DIR *dir;
	struct dirent *read;
	int execution_return = 0;

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
		if (dir)
		{
			while ((read = readdir(dir)) != NULL)
			{
				printf("%s\n", read->d_name);
			}
		}
		else
		{
			fprintf(stderr, "%s: %s '%s': ", argv[0], error_message(errno), argv[1]);
			perror("");
			execution_return = 2;
		}		
	}
	closedir(dir);
	return(execution_return);
}

char *error_message(int error) {
	char *error_messages[3] = {
		"",
		"cannot access",
		"cannot open directory"
	};

	switch (error)
	{
	case 2:
		return error_messages[1];
	case 13:
		return error_messages[2];
	default:
		return error_messages[0];
		break;
	}
}