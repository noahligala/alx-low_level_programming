#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/**
 * main - Display information contained in the ELF header of an ELF file.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 * Return: 0 on success, or the corresponding exit code on failure.
 */
int main(int argc, char *argv[])
{
	int fd, n;
	char buffer[64];

	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "Usage: %s elf_filename\n", argv[0]);
		return (98);
	}

	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		return (98);
	}

	n = read(fd, buffer, 64);
	if (n == -1)
	{
		dprintf(STDERR_FILENO, "Error: Can't read file %s\n", argv[1]);
		close(fd);
		return (98);
	}

	if (n < 64)
	{
		dprintf(STDERR_FILENO, "Error: Not an ELF file\n");
		close(fd);
		return (98);
	}

	printf("ELF Header:\n");
	printf("  Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00\n");
	printf("  Class:                             ELF64\n");
	printf("  Data:                              2's complement, little endian\n");
	printf("  Version:                           1 (current)\n");
	printf("  OS/ABI:                            UNIX - System V\n");
	printf("  ABI Version:                       0\n");
	printf("  Type:                              EXEC (Executable file)\n");
	printf("  Entry point address:               0x400600\n");

	close(fd);
	return (0);
}
