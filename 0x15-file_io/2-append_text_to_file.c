#include "main.h"

/**
 * append_text_to_file - Appends text to the end of a file.
 * @filename: The name of the file to which text will be appended.
 * @text_content: The text to append to the file (a NULL-terminated string).
 *
 * Return: 1 on success, -1 on failure.
 */
int append_text_to_file(const char *filename, char *text_content)
{
	int fd, write_result;
	mode_t mode = S_IRUSR | S_IWUSR;
	int length = 0;

	if (filename == NULL)
		return (-1);

	while (text_content && text_content[length])
		length++;

	fd = open(filename, O_WRONLY | O_APPEND | O_CREAT, mode);
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
