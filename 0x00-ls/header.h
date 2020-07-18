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

/**
 * struct LS_Struct - Ls command struct
 * @directories: List of directories in argv
 * @files: List of files in argv
 * @error_access: List of access errors
 * @error_open: List of open errors
 * @options: List of options in argv
 * @directories_number: Number of directories in @directories
 * @files_number: Number of files in @files
 * @error_access_number: Number of access errors
 * @error_open_number: Number of open errors
 */
typedef struct LS_Struct
{
	char **directories;
	char **files;
	char **error_access;
	char **error_open;
	char options;
	size_t directories_number;
	size_t files_number;
	size_t error_access_number;
	size_t error_open_number;
} LS_Struct_t;

/*
 * Main
 */
int execute(int, char **);

/*
 * Print
 */
void print_directories(LS_Struct_t);
void print_files(LS_Struct_t);
void print_errors_access(LS_Struct_t);
void print_errors_open(LS_Struct_t);

/*
 * Arguments_to_struct
 */
LS_Struct_t get_arguments(int, char **, LS_Struct_t);
LS_Struct_t set_directories(char **, size_t, LS_Struct_t);
LS_Struct_t set_files(char **, size_t, LS_Struct_t);
LS_Struct_t set_errors_access(char **, size_t, LS_Struct_t);
LS_Struct_t set_errors_open(char **, size_t, LS_Struct_t);
LS_Struct_t add_current_directory(LS_Struct_t);

/*
 * Print_format_dir
 */
int get_files_in_dir(char *, LS_Struct_t, size_t);
void print_directories_with_parameters(
	char **,
	char *, char, size_t, LS_Struct_t, size_t);
char **readdir_get_directories(DIR *, size_t *);
void print_dirname_at_start(char *, LS_Struct_t);

/*
 * Print_format_options
 */
void flag_l(char *, char *, char **, size_t);
void flag_a(char **, char *, char *, size_t,
	char,
	size_t);
void flag_A(
	char **,
	size_t,
	size_t);

/*
 * Sort
 */
char **sort_directories_list_by_name(char **, size_t);

/*
 * Lib
 */
int _strcmp_ci(char *, char *);
void free_struct(LS_Struct_t);
char **set_list(char **, char **, size_t, int);

/*
 * Options
 */
char get_options_list(int, char **);
int get_options(char *);
void print_invalid_option(char *, int, int);
void print_unrecognized_option(char *, int);

#endif
