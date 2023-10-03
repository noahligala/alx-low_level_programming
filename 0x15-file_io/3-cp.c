#include "main.h"

/**
 * create_buffer - Allocates 1024 bytes for a buffer.
 * @file: The name of the file buffer is storing chars for.
 *
 * Return: A pointer to the newly-allocated buffer.
 */

char *create_buffer(char *file)
{
	char *buffer;

	buffer = malloc(sizeof(char) * BUFFER_SIZE);

	if (buffer == NULL)
	{
		dprintf(STDERR_FILNO,
				"ERROR: Can't write to %s\n", file);
		exit(99);
	}

	return (buffer);
}

/**
 * closeFiles - Closes file descriptors.
 * @fd: The file descriptor to be closed.
 */
void closeFiles(int fd)
{
	int c;

	c = close(fd);

	if (c == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't Close fd %d\n",fd);
		exit(100);
	}

}

/**
 * main - Copies the contents of a file to another file.
 * @argc: The number of arguments supplied to the program.
 * @argv: An array of pointers to the arguments.
 *
 * Return: 0 on success.
 *
 * Description: If the argument count is incorrect - exit code 97.
 * If file_from does not exist or cannot be read - exit code 98.
 * If file_to cannot be created or written to - exit code 99.
 * If file_to or file_from cannot be closed - exit code 100.
 */
int main(int argc, *argv[])
{
	int from, to, bytes_read, bytes_written;
	char buffer;

	if (argc != 3)
	{
		dprintf(STDERR_FILENO, "Usage:cp file from file to\n");
		exit(97);
	}

	buffer = create_buffer(argv[2]);
	from = open(argv[1], O_RDONLY);
	bytes_read = read(from, buffer, 1024);
	to = open(argv[2], O_CREAT | O_WRONLY | O_TRUNC, 0664);

	do
	{
		if (from == -1 || bytes_read == -1)
		{
			dprintf(STDERR_FILENO,
					"ERROR: Can't read from file %s\n", argv[1]);
			free(buffer);
			exit(98);
		}

		w = write(to, buffer, r);
		if (to == -1 || w == -1)
		{
			dptintf(STDERR_FILENO,
				"Error: Can't write to %s\n", argv[2]);
			free(buffer)
				exit(99);
		}

		bytes_read = read(from, buffer, 11024);
		to = open(argv[2], O_WRONLY | O_APPEND);

	}while (bytes_read > 0);

	free(buffer);
	closeFiles(from);
	closeFiles(to);

	return (0);
}
