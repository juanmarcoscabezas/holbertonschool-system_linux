#ifndef HEADER_FILE
#define HEADER_FILE


#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <dirent.h>
#include <errno.h>
#include <string.h>
#include <ctype.h>
#include <sys/stat.h>
#include <time.h>

char **readdir_get_directories(DIR *, size_t *);
char **sort_directories_list_by_name(char **, size_t);
int show_error_messages(char **, char *, size_t);
void print_directories_with_parameters(char **, char *, char, size_t, size_t);

int _strcmp_ci(char *, char *);
int execute(int, char **);
int get_options(char *);
int opendir_current_in_argv(char **, char *, char, size_t);
char get_options_list(int, char **);
char *error_message(int);
char **get_directories(int, char **, size_t *);

void print_dirname_at_start(char *, int);
void print_endofline_at_end(size_t, char);

void print_invalid_option(char *, int, int);
void print_unrecognized_option(char *, int);

/**
 * struct LS_Struct - Ls command struct
 * @directories: List of directories in argv
 * @options: List of options in argv
 * @directories_number: Number of directories in @directories
 */
typedef struct LS_Struct
{
	char **directories;
	char options;
	size_t directories_number;
} LS_Struct_t;

#endif
