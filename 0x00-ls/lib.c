#include "header.h"

/**
 * show_error_messages - Shows error messages
 * @argv: Application parameters
 * @dir_name: Directory name
 * @directories_number: Number of directories
 * Return: 0 if is a file, 2 otherwise
 */
int show_error_messages(char **argv, char *dir_name, size_t directories_number)
{
	if (errno == 20)
	{
		printf("%s\n", dir_name);
		if (directories_number > 1)
			printf("\n");
		return (0);
	}
	fprintf(stderr, "%s: %s '%s': ", argv[0], error_message(errno), dir_name);
	perror("");
	return (2);
}

/**
 * error_message - This function check for errors
 * @error: Error to be checked
 * Return: An error string
 */
char *error_message(int error)
{
	char *error_messages[3] = {
		"",
		"cannot acces",
		"cannot open director"};

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
			return ((tolower(*s2) - tolower(*s1)) * -1);
		s1++;
		s2++;
	}
	return (0);
}
