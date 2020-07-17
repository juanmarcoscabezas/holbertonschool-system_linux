#include "header.h"

/**
 * get_options_list - Gets an options list
 * @argc: Application parameters length
 * @argv: Application parameters
 * Return: The options list
 */
char get_options_list(int argc, char **argv)
{
	int argc_iterator;

	for (argc_iterator = 1; argc_iterator < argc; argc_iterator++)
	{
		if (strlen(argv[argc_iterator]) == 2)
			if (argv[argc_iterator][0] == '-' && argv[argc_iterator][1] == '-')
				return ('\0');
		if (argv[argc_iterator][0] == '-')
			return (get_options(argv[argc_iterator]));
	}
	return ('\0');
}

/**
 * get_options - Gets and option
 * @option: Option to get in the user input
 * Return: An option;
 */
int get_options(char *option)
{
	int option_iterator;
	size_t flags_iterator;
	int option_length = 0;
	int correct_flag = 0;

	char *flags = "aArStR1l";

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
					return (flags[flags_iterator]);
				}
			}
			if (correct_flag == 0)
			{
				printf("./hls: invalid option -- '%c'\n", option[option_iterator]);
				printf("Try './hls --help' for more information.\n");
				exit(2);
			}
			correct_flag = 0;
		}
	}
	return (0);
}
