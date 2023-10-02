#include "main.h"

#define BUFFER_SIZE 1024

/**
 * main - Copy the content of one file to another.
 * @argc: The number of arguments.
 * @argv: An array of argument strings.
 *
 * Return: 0 on success, or an error code on failure.
 */

int openSourceFile(const char *filename);
int openDestinationFile(const char *filename);
int copyFile(int source_fd, int dest_fd);

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


int openSourceFile(const char *filename)
{
    int fd = open(filename, O_RDONLY);
    if (fd == -1)
    {
        dprintf(2, "Error: Can't read from file %s\n", filename);
        return -1;
    }
    return fd;
}

int openDestinationFile(const char *filename)
{
    int fd_dest = open(filename, O_WRONLY | O_CREAT | O_TRUNC, S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH);
    if (fd_dest == -1)
    {
        dprintf(2, "Error: Can't write to %s\n", filename);
        return -1;
    }
    return fd_dest;
}

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
            return -1;
        }
    }

    if (bytes_read == -1)
    {
        dprintf(2, "Error: Can't read from source file\n");
        return -1;
    }

    return 0;
}
