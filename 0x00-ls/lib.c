#include "header.h"

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

void free_struct(LS_Struct_t ls_struct)
{
	if (ls_struct.directories)
		free(ls_struct.directories);
	if (ls_struct.files)
		free(ls_struct.files);
	if (ls_struct.error_access)
		free(ls_struct.error_access);
	if (ls_struct.error_open)
		free(ls_struct.error_open);
}
