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

	option_length = strlen(option);

	if (option[0] == '-')
	{
		if (strlen(option) >= 3)
		{
			if (option[1] == '-')
				print_unrecognized_option(option, correct_flag);
		}
		for (option_iterator = 1; option_iterator < option_length; option_iterator++)
		{
			if (option_iterator == 1 && option[option_iterator] == '-')
				continue;
			for (flags_iterator = 0; flags_iterator < strlen(flags); flags_iterator++)
				if (flags[flags_iterator] == option[option_iterator])
				{
					correct_flag = 1;
					return (flags[flags_iterator]);
				}
			print_invalid_option(option, correct_flag, option_iterator);
			correct_flag = 0;
		}
	}
	return (0);
}

/**
 * print_unrecognized_option - Prints if an option is unrecognized
 * @option: Current option
 * @correct_flag: 1 on success, 0 otherwise
 * Return:
 */
void print_unrecognized_option(char *option, int correct_flag)
{
	if (correct_flag == 0)
	{
		fprintf(stderr, "hls: unrecognized option '%s'\n", option);
		fprintf(stderr, "Try 'hls --help' for more information.\n");
		exit(2);
	}
}

/**
 * print_invalid_option - Prints if an option is invalid
 * @option: Current option
 * @correct_flag: 1 on success, 0 otherwise
 * @option_iterator: Current position on @option string
 * Return:
 */
void print_invalid_option(char *option, int correct_flag, int option_iterator)
{
	if (correct_flag == 0)
	{
		fprintf(stderr, "hls: invalid option -- '%c'\n", option[option_iterator]);
		fprintf(stderr, "Try 'hls --help' for more information.\n");
		exit(2);
	}
}
