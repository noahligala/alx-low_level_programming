#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include "main.h"

/**
 * create_file - creates a file with the given content anf permissions.
 * @filename: the name of the file to create.
 * @text_content: The content to write to the file (a NULL-terminated string).
 *
 * Return: 1 on Success, -1 on failure.
 */

int create_file(const char *filename, char *text_content)
{
	int fd, write_result;
	mode_t mode = S_IRUSR | S_IWUSR;
	int length = 0;

	if (filename == NULL)
		return (-1);

	while (text_content && text_content[length])
		length++;

	fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, mode);
	if (fd == -1)
		return (-1);

	if (text_content)
	{
		write_result = write(fd, text_content, length);
		if (write_result == -1)
		{
			close(fd);
			return (-1);
		}
	}

	close(fd);
	return (1);
}
