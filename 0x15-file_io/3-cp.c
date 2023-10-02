#include "main.h"

/**
 * main - Copy the content of one file to another.
 * @argc: The number of arguments.
 * @argv: An array of argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */

int main(int argc, char *argv[])
{
	int source_fd, dest_fd;

	if (argc != 3)
	{
		dprintf(2, "Usage: %s file_from file_to\n", argv[0]);
		return (97);
	}

	source_fd = openSourceFile(argv[1]);
	dest_fd = openDestinationFile(argv[2]);

	if (source_fd == -1 || dest_fd == -1)
		return (98);

	if (copyFile(source_fd, dest_fd) == -1)
	{
		closeFiles(source_fd, dest_fd);
		return (99);
	}

	closeFiles(source_fd, dest_fd);
	return (0);
}

/**
 * openSourceFile - Opens a source file for reading.
 * @filename: the name of the source file
 *
 * Return: The file descriptor of the opened file, or -1 on failure.
 */

int openSourceFile(const char *filename)
{
	int fd = open(filename, O_RDONLY);

	if (fd == -1)
	{
		dprintf(2, "Error: Can't read from file %s\n", filename);
		return (-1);
	}
	return (fd);
}

/**
 * openDestinationFile - Opens a destination file for writing.
 * @filename: The name of the destination file to open or create.
 *
 * Return: The file descriptor of the opened file, or -1 on failure.
 */

int openDestinationFile(const char *filename)
{
	int fd_dest = open(filename,
			O_WRONLY | O_CREAT | O_TRUNC,
			S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);

	if (fd_dest == -1)
	{
		dprintf(2, "Error: Can't write to %s\n", filename);
		return (-1);
	}
	return (fd_dest);
}

/**
 * copyFile - Copies the content of one file to another.
 * @source_fd: The file descriptor of the source file.
 * @dest_fd: The file descriptor of the destination file.
 *
 * Return: 0 on success, or -1 on failure.
 */
int copyFile(int source_fd, int dest_fd)
{
	char buffer[BUFFER_SIZE];
	ssize_t bytes_read, bytes_written;

	while ((bytes_read = read(source_fd, buffer, BUFFER_SIZE)) > 0)
	{
		bytes_written = write(dest_fd, buffer, bytes_read);
		if (bytes_written == -1 || bytes_written != bytes_read)
		{
			dprintf(2, "Error: Can't write to destination file\n");
			return (-1);
		}
	}
	if (bytes_read == -1)
	{
		dprintf(2, "Error: Can't read from source file\n");
		return (-1);
	}

	return (0);
}

/**
 * closeFiles - Closes file descriptors for source and destination files.
 * @source_fd: The file descriptor of the source file.
 * @dest_fd: The file descriptor of the destination file.
 *
 * This function closes the specified file descriptors.
 * If an error occurs while closing a file descriptor, it prints an error msg.
 */
void closeFiles(int source_fd, int dest_fd)
{
	if (close(source_fd) == -1 || close(dest_fd) == -1)
	{
		dprintf(2, "Error: Can't close file descriptor\n");
		exit(100);
	}
}
