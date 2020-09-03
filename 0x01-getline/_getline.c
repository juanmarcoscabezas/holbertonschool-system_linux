#include "_getlne.h"

char *_getline(const int fd)
{
	char static buffer[READ_SIZE];
	size_t static buffer_position;
	size_t iterator;
	static int read_bytes;

	char *buffer_returned;
	buffer_returned = malloc(sizeof(char) * READ_SIZE);

	for (iterator = 0; buffer[iterator] != '\n' && iterator < READ_SIZE; iterator++);

	read_bytes = read(fd, buffer, READ_SIZE);

	if (read_bytes == 0)
		return (NULL);

	buffer_position = iterator;

	printf("%s", buffer_returned);
	return (NULL);
}

char *_read_line(char *buffer)
{

}
